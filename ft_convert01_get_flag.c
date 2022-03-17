#include "ft_printf.h"

static int	is_option(const char c)
{
	int			val_flag;
	size_t		i;
	const char	*option_set = "#-+ 0";

	val_flag = 0;
	i = 0;
	while (i < ft_strlen(option_set))
	{
		if (option_set[i] == c)
			val_flag |= (1 << i);
		i++;
	}
	return (val_flag);
}

size_t	get_option_flag(const char *fmt, int *b_flag)
{
	size_t	i;

	i = 0;
	while (is_option(fmt[i]) != 0)
	{
		*b_flag |= is_option(fmt[i]);
		i++;
	}
	if (*b_flag & FLAG_HYPHEN)
		*b_flag &= ~FLAG_ZERO;
	if (*b_flag & FLAG_PLUS)
		*b_flag &= ~FLAG_SPACE;
	return (i);
}

static int	is_spec(const char c)
{
	int			val_flag;
	size_t		i;
	const char	*spec_set = "cspdiuxX";

	val_flag = 0;
	i = 0;
	while (i < ft_strlen(spec_set))
	{
		if (spec_set[i] == c)
			val_flag |= (1 << (i + 8));
		i++;
	}
	return (val_flag);
}

void	get_spec_flag(const char *fmt, int *b_flag)
{
	size_t	i;

	i = 0;
	while (is_spec(fmt[i]) != 0)
	{
		*b_flag |= is_spec(fmt[i]);
		i++;
	}
}
