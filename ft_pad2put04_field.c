#include "ft_printf.h"

static void	padding_zero(char *str, size_t len_s, int flag, size_t len_pad);
static void	padding_space(char *str, size_t len_s, int flag, size_t len_pad);
static void paddinng_char(char *str, size_t len_s, size_t len_pad, char c);
static void add_case_nega(char *str, size_t len_pad, char *sign);

void	pad_field(char *str, size_t len_s, size_t field, int flag)
{
	size_t	len_pad;

	len_pad = field - len_s;
	if (flag & FLAG_HYPHEN && flag & FLAG_C)
		ft_memset(&str[1], ' ', field - 1);
    else if (flag & FLAG_C)
		ft_memset(str, ' ', field - 1);
    else if (flag & FLAG_HYPHEN)
		ft_memset(&str[len_s], ' ', len_pad);
	else if (flag & FLAG_ZERO && is_diux_flag(flag) == 1 && !(flag & FLAG_IS_PREC))
		padding_zero(str, len_s, flag, len_pad);
	else
        padding_space(str, len_s, flag, len_pad);
}

static void	padding_zero(char *str, size_t len_s, int flag, size_t len_pad)
{
    paddinng_char(str, len_s, len_pad, '0');
	if (flag & FLAG_NEGA)
        add_case_nega(str, len_pad, "0");
    if (flag & FLAG_NUMBER_SIGN)
        ft_memmove(&str[0], "0x", 2);
}

static void	padding_space(char *str, size_t len_s, int flag, size_t len_pad)
{
    if (flag & FLAG_NUMBER_SIGN)
        paddinng_char(str, len_s + 2, len_pad - 2, ' ');
    else
        paddinng_char(str, len_s, len_pad, ' ');
	if (flag & FLAG_NEGA)
        add_case_nega(str, len_pad, " ");
}

static void paddinng_char(char *str, size_t len_s, size_t len_pad, char c)
{
    ft_memmove(&str[len_pad], str, len_s);
    ft_memset(str, c, len_pad);
}

static void add_case_nega(char *str, size_t len_pad, char *sign)
{
    ft_memmove(&str[len_pad], sign, 1);
    str[0] = '-';
}