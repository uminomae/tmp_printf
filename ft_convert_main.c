#include "ft_printf.h"

static char	*convert_ap_in_spec(const char *fmt, va_list *ap, int *b_flag);

int	cnvrt_ap_to_output(const char *fmt, va_list *ap, size_t *i)
{
	int         b_flag;
	char        *conv_str;
    int         len_put;
    long long   two_width;
    size_t      j;

    two_width = 0;
	b_flag = 0;
    j = 1;
	j += get_option_flag(&fmt[j], &b_flag);
	j += get_field_w(&fmt[j], &two_width, &b_flag);
	j += get_prec_w(&fmt[j], &two_width, &b_flag);
	get_spec_flag(&fmt[j], &b_flag);
	conv_str = convert_ap_in_spec(&fmt[j], ap, &b_flag);
	if (conv_str == NULL)
		return (-1);
	*i += j + 1;
    len_put = put_with_pad_ap(conv_str, b_flag, (two_width & GET_FIELD), (two_width>>32));
    free(conv_str);
	return (len_put);
}

static char	*convert_ap_in_spec(const char *fmt, va_list *ap, int *b_flag)
{
	char	*conv_s;

	conv_s = NULL;
	if (*fmt == 'c')
    {
        conv_s = convert_c((unsigned char)va_arg(*ap, int));
        if (conv_s[0] == 0)
            *b_flag |= FLAG_C0;
    }
    else if (*fmt == '%')
		conv_s = convert_c('%');
	else if (*fmt == 's')
        conv_s = convert_s(va_arg(*ap, char *));
    else if (*fmt == 'p')
		conv_s = convert_p(va_arg(*ap, void *));
	else if (*fmt == 'd' || *fmt == 'i')
		conv_s = convert_di(va_arg(*ap, int), b_flag);
	else if (*fmt == 'u')
		conv_s = convert_uint(va_arg(*ap, unsigned int), 10);
	else if (*fmt == 'x' || *fmt == 'X')
		conv_s = convert_uint(va_arg(*ap, unsigned int), 16);
	else
		return (NULL);
	return (conv_s);
}
