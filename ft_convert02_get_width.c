#include "ft_printf.h"

size_t	get_field_w(const char *fmt, long long *b_width, int *b_flag)
{
	size_t	i;
    size_t  field_w;

    field_w = 0;
	i = 0;
	while (ft_isdigit(fmt[i]) != 0)
	{
		*b_flag |= FLAG_IS_FIELD;
        field_w = field_w * 10 + (fmt[i] - '0');
		i++;
	}
        *b_width = field_w;
	return (i);
}

size_t	get_prec_w(const char *fmt, long long *b_width, int *b_flag)
{
	size_t	i;
    size_t prec_w;

    prec_w = 0;
	i = 0;
	if (fmt[i] == '.')
	{
		*b_flag |= FLAG_IS_PREC;
		i += 1;
		if (ft_isdigit(fmt[i]) == 0)
            prec_w = 0;
		while (ft_isdigit(fmt[i]) != 0)
		{
			prec_w = prec_w * 10 + (fmt[i] - '0');
			i++;
		}
	}
    *b_width = (prec_w<<32)|*b_width;
	return (i);
}
