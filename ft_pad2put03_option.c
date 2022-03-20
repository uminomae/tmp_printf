#include "ft_printf.h"

static size_t	add_0x(char *str, size_t len, int flag);
static size_t	add_sign_space(char *str, size_t len, int flag, char *c);

size_t	add_fmt_option(char *str, size_t len, int flag)
{
	if (flag & FLAG_NUMBER_SIGN)
		len = add_0x(str, len, flag);
	if (flag & FLAG_PLUS)
		len = add_sign_space(str, len, flag, "+");
	if (flag & FLAG_SPACE)
		len = add_sign_space(str, len, flag, " ");
	return (len);
}

static size_t	add_0x(char *str, size_t len, int flag)
{
    if (flag & FLAG_ZERO)
        return (len);
	if (flag & FLAG_X || flag & FLAG_LX)
	{
		if (str[0] == '0' && ft_strlen(str) == 1)
			return (len);
		ft_memmove(&str[2], str, len);
		ft_memmove(&str[0], "0x", 2);
		len += 2;
	}
	return (len);
}

static size_t	add_sign_space(char *str, size_t len, int flag, char *sign)
{
	if (flag & FLAG_D || flag & FLAG_I)
	{
		if (flag & FLAG_NEGA)
			return (len);
		ft_memmove(&str[1], str, len);
		ft_memmove(&str[0], sign, 1);
		len += 1;
	}
	return (len);
}