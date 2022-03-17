#include "ft_printf.h"

static void	padding_zero(char *str, size_t len_s, int b_flag, size_t pad_w);
static void	padding_space(char *str, size_t len_s, int b_flag, size_t pad_w);
static void paddinng_char(char *str, size_t len_s, size_t pad_w, char c);
static void add_case_nega(char *str, size_t pad_w, char *sign);

void	pad_field(char *str, size_t len_s, size_t field_w, int b_flag)
{
	size_t	pad_w;

	pad_w = field_w - len_s;
	if (b_flag & FLAG_HYPHEN && b_flag & FLAG_C)
		ft_memset(&str[1], ' ', field_w - 1);
    else if (b_flag & FLAG_C)
		ft_memset(str, ' ', field_w - 1);
    else if (b_flag & FLAG_HYPHEN)
		ft_memset(&str[len_s], ' ', pad_w);
	else if (b_flag & FLAG_ZERO && is_diux_flag(b_flag) == 1 && !(b_flag & FLAG_IS_PREC))
		padding_zero(str, len_s, b_flag, pad_w);
	else
        padding_space(str, len_s, b_flag, pad_w);
}

static void	padding_zero(char *str, size_t len_s, int b_flag, size_t pad_w)
{
    paddinng_char(str, len_s, pad_w, '0');
	if (b_flag & FLAG_NEGA)
        add_case_nega(str, pad_w, "0");
    if (b_flag & FLAG_HASH)
        ft_memmove(&str[0], "0x", 2);
}

static void	padding_space(char *str, size_t len_s, int b_flag, size_t pad_w)
{
    if (b_flag & FLAG_HASH)
        paddinng_char(str, len_s + 2, pad_w - 2, ' ');
    else
        paddinng_char(str, len_s, pad_w, ' ');
	if (b_flag & FLAG_NEGA)
        add_case_nega(str, pad_w, " ");
}

static void paddinng_char(char *str, size_t len_s, size_t pad_w, char c)
{
    ft_memmove(&str[pad_w], str, len_s);
    ft_memset(str, c, pad_w);
}

static void add_case_nega(char *str, size_t pad_w, char *sign)
{
    ft_memmove(&str[pad_w], sign, 1);
    str[0] = '-';
}