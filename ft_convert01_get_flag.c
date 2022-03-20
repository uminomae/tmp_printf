#include "ft_printf.h"

static int	get_bit_flag(const char c, char *set, size_t n)
{
    int     val_flag;
    size_t  i;
    size_t  len;

	val_flag = 0;
    len = ft_strlen(set);
	i = 0;
	while (i < len)
	{
		if (set[i] == c)
			val_flag |= (1 << (i + n));
		i++;
	}
	return (val_flag);
}

size_t	get_option_flag(const char *fmt, int *flag)
{
	size_t	i;

	i = 0;
   	while (get_bit_flag(fmt[i], SET_OPTION, SHIFT_OPTION) != 0)
	{
		*flag |= get_bit_flag(fmt[i], SET_OPTION, SHIFT_OPTION);
		i++;
	}
	if (*flag & FLAG_HYPHEN)
		*flag &= ~FLAG_ZERO;
	if (*flag & FLAG_PLUS)
		*flag &= ~FLAG_SPACE;
	return (i);
}

void	get_spec_flag(const char *fmt, int *flag)
{
    *flag |= get_bit_flag(*fmt, SET_SPEC, SHIFT_SPEC);
}