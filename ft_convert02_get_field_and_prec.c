#include "ft_printf.h"

static int  get_length_atoi(const char *fmt, size_t len)
{
    size_t  next;

    next = (*fmt - '0');
    if (len * 10 + next > INT_MAX)
        return (-1);
    len = len * 10 + next;
    return (len);
}

size_t	get_field_width(const char *fmt, t_fmt *list, int *flag)
{
    size_t  field_width;
    size_t  next;
	size_t	i;

    field_width = 0;
    next = 0;
	i = 0;
    if (ft_isdigit(fmt[i]) != 0)
		*flag |= FLAG_IS_FIELD;
	while (ft_isdigit(fmt[i]) != 0)
	{
        field_width = get_length_atoi(&fmt[i], field_width);
		i++;
	}
    list->field = field_width;
	return (i);
}

size_t	get_precision_len(const char *fmt, t_fmt *list, int *flag)
{
    size_t  precision;
    size_t  next;
	size_t	i;

    precision = 0;
    next = 0;
	i = 0;
	if (fmt[i] == '.')
	{
		*flag |= FLAG_IS_PREC;
		i += 1;
		while (ft_isdigit(fmt[i]) != 0)
		{
            precision = get_length_atoi(&fmt[i], precision);
			i++;
		}
	}
    list->precision = precision;
	return (i);
}