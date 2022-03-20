#include "ft_printf.h"

static size_t	numerical_case(char *dst, size_t len_s, size_t prec, int flag);
static void flag_nega(char *dst, size_t len_s, size_t len_pad);
static void normal_case(char *dst, size_t len_s, size_t len_pad);
static void flag_number_sign(char *dst, size_t prec, int flag);

size_t	pad_precision(char *dst, size_t len_s, size_t prec, int flag)
{
   	if (is_diux_flag(flag) == 1)
		len_s = numerical_case(dst, len_s, prec, flag);
	if (len_s > prec && (flag & FLAG_S))
	{
		len_s = prec;
        dst[len_s] = '\0';
	}
	return (len_s);
}

static size_t   numerical_case(char *dst, size_t len_s, size_t prec, int flag)
{
	size_t	len_pad;

	len_pad = 0;
	if (len_s <= prec)
	{
		len_pad = prec - len_s;
		if (flag & FLAG_NEGA)
            flag_nega(dst, len_s, len_pad);
		else
            normal_case(dst, len_s, len_pad);
        if (flag & FLAG_NUMBER_SIGN)
            flag_number_sign(dst, prec, flag);
		len_s = prec;
	}
	return (len_s);
}

static void flag_nega(char *dst, size_t len_s, size_t len_pad)
{
    ft_memmove(&dst[len_pad + 2], &dst[1], len_s - 1);
    ft_memset(&dst[1], '0', len_pad + 1);
    dst[0] = '-';
}

static void normal_case(char *dst, size_t len_s, size_t len_pad)
{
    ft_memmove(&dst[len_pad], dst, len_s);
    ft_memset(dst, '0', len_pad);
}

static void flag_number_sign(char *dst, size_t prec, int flag)
{
    if (flag & FLAG_X || flag & FLAG_LX)
    {
        ft_memmove(&dst[2], dst, prec);
        ft_memmove(dst, "0x", 2);
    }
}