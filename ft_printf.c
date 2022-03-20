#include "ft_printf.h"

static int  sum_output_char(const char *fmt, va_list *ap);
static int  convert_and_print(const char *fmt, va_list *ap, size_t *i);
static ssize_t	get_len_until_percent(const char *fmt);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len_total;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	len_total = sum_output_char(fmt, &ap);
	va_end(ap);
	return (len_total);
}

static int  sum_output_char(const char *fmt, va_list *ap)
{
    int		len_total;
    int     len_sub_total;
    size_t	i;
    
    len_total = 0;
    len_sub_total = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		len_sub_total = convert_and_print(fmt, ap, &i);
		if (len_sub_total < 0)
			return (-1);
        len_total += len_sub_total;
	}
    return (len_total);
}

static int	convert_and_print(const char *fmt, va_list *ap, size_t *i)
{
	int		len_sub_total;
	int 	len_output;

	len_sub_total = 0;
	len_output = 0;
	if (fmt[*i] == '%')
	{
        len_output = convert_main(&fmt[*i], ap, i);
		if (len_output == -1)
			return (-1);
	}
	else
	{
		len_output = get_len_until_percent(&fmt[*i]);
    	if (len_output == -1)
	    	return (-1);
        write(1, &fmt[*i], len_output);
		*i += len_output;
	}
	len_sub_total += len_output;
	return (len_sub_total);
}

static ssize_t	get_len_until_percent(const char *fmt)
{
	size_t	i;

	i = 0;
	while (fmt[i] != '%' && fmt[i] != '\0')
		i++;
    if (i > INT_MAX)
        return (-1);
	return (i);
}