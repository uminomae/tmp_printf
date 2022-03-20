#include "ft_printf.h"

static t_fmt   *list_init(void);
static char *convert_arg_with_spec(const char *fmt, va_list *ap, int *flag);

int	convert_main(const char *fmt, va_list *ap, size_t *i)
{
    t_fmt       *list;
	int         flag;
    size_t      j;
	char        *conv_str;
    int         len_put;

    list = list_init();
	flag = 0;
    j = 1;
	j += get_option_flag(&fmt[j], &flag);
	j += get_field_width(&fmt[j], list, &flag);
	j += get_precision_len(&fmt[j], list, &flag);
	get_spec_flag(&fmt[j], &flag);
	conv_str = convert_arg_with_spec(&fmt[j], ap, &flag);
	if (conv_str == NULL)
		return (-1);
	*i += j + 1;
    len_put = output_with_padded(conv_str, flag, list->field, list->precision);
    free(conv_str);
    free(list);
	return (len_put);
}

static t_fmt   *list_init(void)
{
    t_fmt    *new;
    
    new = (t_fmt *)ft_calloc(1, sizeof(t_fmt));
    new->field = 0;
    new->precision = 0;
    return (new);
}

static char	*convert_arg_with_spec(const char *fmt, va_list *ap, int *flag)
{
	char	*conv_str;

	conv_str = NULL;
	if (*fmt == 'c')
    {
        conv_str = convert_c((unsigned char)va_arg(*ap, int));
        if (conv_str[0] == 0)
            *flag |= FLAG_C0;
    }
    else if (*fmt == '%')
		conv_str = convert_c('%');
	else if (*fmt == 's')
        conv_str = convert_s(va_arg(*ap, char *));
    else if (*fmt == 'p')
		conv_str = convert_p(va_arg(*ap, void *));
	else if (*fmt == 'd' || *fmt == 'i')
		conv_str = convert_di(va_arg(*ap, int), flag);
	else if (*fmt == 'u')
		conv_str = convert_uint(va_arg(*ap, uint32_t), 10);
	else if (*fmt == 'x' || *fmt == 'X')
		conv_str = convert_x(va_arg(*ap, uint32_t), 16);
	else
		return (NULL);
	return (conv_str);
}

int	output_with_padded(char *conv_str, int flag, size_t field, size_t prec)
{
	char	*put_str;
	size_t	len_s;
    size_t	len_put_s;
    size_t  len_ret;

	put_str = get_alloc_size(conv_str, flag, field, prec);
    if (put_str == NULL)
        return (-1);
	len_s = ft_strlen(conv_str);
	ft_memmove(put_str, conv_str, len_s);
    if (flag & FLAG_IS_PREC)
        len_s = pad_precision(put_str, len_s, prec, flag);
	len_s = add_fmt_option(put_str, len_s, flag);
	if (len_s < field && (flag & FLAG_IS_FIELD))
		pad_field(put_str, len_s, field, flag);
	if (flag & FLAG_LX)
		put_str = to_upper_str(put_str);
    len_put_s = ft_strlen(put_str);
    len_ret = write_put_str(put_str, flag, field, len_put_s);
	return (len_ret);
}

int	is_diux_flag(int flag)
{
	if (flag & FLAG_D || flag & FLAG_I)
		return (1);
	if (flag & FLAG_U || flag & FLAG_X || flag & FLAG_LX)
		return (1);
	return (0);
}