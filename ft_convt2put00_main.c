#include "ft_printf.h"

// static t_fmt   *list_init(void);
// static char *convert_arg_with_spec(const char *fmt, va_list *ap, int *flag);
// static unsigned char    call_arg_c(const char *fmt, va_list *ap);

static unsigned char call_arg_c(const char *fmt, va_list *ap)
{
    if (*fmt == '%')
        return ('%');
    else
        return ((unsigned char)va_arg(*ap, int));
}

static char	*convert_arg_with_spec(const char *fmt, va_list *ap, int *flag)
{
	char	*conv_str;

	if (*fmt == 'c' || *fmt == '%')
    {
        conv_str = convert_c(call_arg_c(fmt, ap));
        if (conv_str[0] == 0)
            *flag |= FLAG_C0;
        if (*fmt == '%')
            *flag |= FLAG_PERC;
    }
    else if (*fmt == 's')
        conv_str = convert_s(va_arg(*ap, char *));
    else if (*fmt == 'p')
		conv_str = convert_p(va_arg(*ap, void *), flag);
	else if (*fmt == 'd' || *fmt == 'i')
		conv_str = convert_di(va_arg(*ap, int), flag);
    else if (*fmt == 'u')
		conv_str = convert_uint(va_arg(*ap, uint32_t), flag, 10);
	else if (*fmt == 'x' || *fmt == 'X')
		conv_str = convert_x(va_arg(*ap, uint32_t), flag, 16);
	else
		return (NULL);
	return (conv_str);
}

static t_fmt   *list_init(void)
{
    t_fmt    *new;
    
    new = (t_fmt *)ft_calloc(1, sizeof(t_fmt));
    new->field = 0;
    new->precision = 0;
    return (new);
}

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

int	output_with_padded(char *conv_str, int flag, size_t field, size_t prec)
{
	char	*put_str;
	size_t	len_str;
    size_t  len_ret;

	put_str = get_alloc_size(conv_str, flag, field, prec);
    if (put_str == NULL)
        return (-1);
	len_str = ft_strlen(conv_str);
	ft_memmove(put_str, conv_str, len_str);
    if (flag & FLAG_IS_PREC)
        len_str = pad_precision(put_str, len_str, prec, flag);
	len_str = add_fmt_option(put_str, len_str, flag);
    if (len_str < field)
		pad_field(put_str, len_str, field, flag);
	if (flag & FLAG_LX)
		put_str = to_upper_str(put_str);
    len_ret = write_put_str(put_str, flag, field);
	return (len_ret);
}