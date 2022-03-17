#include "ft_printf.h"

static int      write_or_convert(const char *fmt, va_list *ap, size_t *i);
static ssize_t	strlen_to_percent_or_end(const char *fmt);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total_len;
    int     sub_total_len;
	size_t	i;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	total_len = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		sub_total_len = write_or_convert(fmt, &ap, &i);
		if (sub_total_len == -1)
			return (-1);
        total_len += sub_total_len;
	}
	va_end(ap);
	return (total_len);
}

static int	write_or_convert(const char *fmt, va_list *ap, size_t *i)
{
	int		sub_total_len;
	int 	write_len;

	sub_total_len = 0;
	write_len = 0;
	if (fmt[*i] == '%')
	{
        write_len = cnvrt_ap_to_output(&fmt[*i], ap, i);
		if (write_len == -1)
			return (-1);
	}
	else
	{
		write_len = strlen_to_percent_or_end(&fmt[*i]);
    	if (write_len == -1)
	    	return (-1);
        write(1, &fmt[*i], write_len);
		*i += write_len;
	}
	sub_total_len += write_len;
	return ((int)sub_total_len);
}

static ssize_t	strlen_to_percent_or_end(const char *fmt)
{
	size_t	i;

	i = 0;
	while (fmt[i] != '%' && fmt[i] != '\0')
		i++;
    if (INT_MAX < i)
        return (-1);
	return (i);
}