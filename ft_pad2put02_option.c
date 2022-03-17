#include "ft_printf.h"

static size_t	add_0x(char *str, size_t len, int b_flag);
static size_t	add_sign_space(char *str, size_t len, int b_flag, char *c);

size_t	add_fmt_option(char *str, size_t len, int b_flag)
{
	if (b_flag & FLAG_HASH)
		len = add_0x(str, len, b_flag);
	if (b_flag & FLAG_PLUS)
		len = add_sign_space(str, len, b_flag, "+");
	if (b_flag & FLAG_SPACE)
		len = add_sign_space(str, len, b_flag, " ");
	return (len);
}

static size_t	add_0x(char *str, size_t len, int b_flag)
{
    if (b_flag & FLAG_ZERO)
        return (len);
	if (b_flag & FLAG_X || b_flag & FLAG_LX)
	{
		if (str[0] == '0' && ft_strlen(str) == 1)
			return (len);
		ft_memmove(&str[2], str, len);
		ft_memmove(&str[0], "0x", 2);
		len += 2;
	}
	return (len);
}

static size_t	add_sign_space(char *str, size_t len, int b_flag, char *sign)
{
	if (b_flag & FLAG_D || b_flag & FLAG_I)
	{
		if (b_flag & FLAG_NEGA)
			return (len);
		ft_memmove(&str[1], str, len);
		ft_memmove(&str[0], sign, 1);
		len += 1;
	}
	return (len);
}