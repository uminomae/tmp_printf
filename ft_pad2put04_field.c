#include "ft_printf.h"

static void	padding_zero(char *str, size_t len_s, int flag, size_t len_pad);
static void	padding_space(char *str, size_t len_s, int flag, size_t len_pad);
static void paddinng_char(char *str, size_t len_s, size_t len_pad, char c);
static void add_case_sign(char *str, size_t len_pad, char *pad_char, char sign);

void	pad_field(char *str, size_t len_s, size_t field, int flag)
{
	size_t	len_pad;

    len_pad = field - len_s;
	if (flag & FLAG_HYPHEN && flag & FLAG_C)
		ft_memset(&str[1], ' ', field - 1);
    else if (flag & FLAG_C)
        padding_space(str, len_s, flag, field - 1);
    else if (flag & FLAG_ZERO && flag & FLAG_PERC)
        padding_zero(str, len_s, flag, field - 1);
    else if (flag & FLAG_HYPHEN)
		ft_memset(&str[len_s], ' ', len_pad);
	else if (flag & FLAG_ZERO && is_diux_flag(flag) == 1 && !(flag & FLAG_IS_PREC))
		padding_zero(str, len_s, flag, len_pad);
	else
        padding_space(str, len_s, flag, len_pad);
}

static void	padding_zero(char *str, size_t len_s, int flag, size_t len_pad)
{
    const size_t    prefix_size = sizeof("0x") - 1;

    paddinng_char(str, len_s, len_pad, '0');
	if (flag & FLAG_NEGA)
        add_case_sign(str, len_pad, "0", '-');
    if (flag & FLAG_PLUS && !(flag & FLAG_NEGA))
        add_case_sign(str, len_pad, "0", '+');
    if (flag & FLAG_SPACE && !(flag & FLAG_NEGA))
        add_case_sign(str, len_pad, "0", ' ');
    if (flag & FLAG_NUMBER_SIGN && !(flag & FLAG_D0))
    {
        ft_memset(str, '0', len_pad + prefix_size);
        ft_memmove(&str[0], "0x", prefix_size);
    }
}

static void	padding_space(char *str, size_t len_s, int flag, size_t len_pad)
{
    if (flag & FLAG_NUMBER_SIGN)
        paddinng_char(str, len_s, len_pad, ' ');
    else
        paddinng_char(str, len_s, len_pad, ' ');
}

static void paddinng_char(char *str, size_t len_s, size_t len_pad, char c)
{
    ft_memmove(&str[len_pad], str, len_s);
    ft_memset(str, c, len_pad);
}

static void add_case_sign(char *str, size_t len_pad, char *pad_char, char sign)
{
    ft_memmove(&str[len_pad], pad_char, 1);
    str[0] = sign;
}