#include "ft_printf.h"

// static size_t	padding_num_case(char *dst, size_t len_s, size_t prec, int flag);
// static void add_sign_and_pad(char *dst, size_t len_s, size_t len_pad);
// static void paddig_zero(char *dst, size_t len_s, size_t len_pad);


static void add_sign_and_pad(char *dst, size_t len_s, size_t len_pad)
{
    char    *shift_sign_and_pad;
    char    *next_to_sign;
    size_t  absolute_val;
    size_t  num_padding;

    shift_sign_and_pad = &dst[len_pad + 2];
    next_to_sign = &dst[1];
    absolute_val = len_s - 1;
    num_padding = len_pad + 1;
    ft_memmove(shift_sign_and_pad, next_to_sign, absolute_val);
    ft_memset(next_to_sign, '0', num_padding);
    dst[0] = '-';
}

static void paddig_zero(char *dst, size_t len_s, size_t len_pad)
{
    ft_memmove(&dst[len_pad], dst, len_s);
    ft_memset(dst, '0', len_pad);
}

static size_t   padding_num_case(char *dst, size_t len_s, size_t prec, int flag)
{
	size_t	len_pad;

	len_pad = 0;
    if (flag & FLAG_D0 && prec == 0)
    {
        dst[0] = '\0';
        len_s = 0;
    }
    if (len_s <= prec)
	{
		len_pad = prec - len_s;
		if (flag & FLAG_NEGA)
        {
            add_sign_and_pad(dst, len_s, len_pad);
            len_s = prec + 1;
        }
        else
        {
            paddig_zero(dst, len_s, len_pad);
		    len_s = prec;
        }
	}
	return (len_s);
}


size_t	pad_precision(char *dst, size_t len_s, size_t prec, int flag)
{
    size_t len_pad;

    len_pad = len_s - prec;
   	if (is_diux_flag(flag) == 1)
		len_s = padding_num_case(dst, len_s, prec, flag);
	if (len_s > prec && (flag & FLAG_S))
	{
		len_s = prec;
        ft_memset(&dst[prec], '\0', len_pad);
	}
	return (len_s);
}


// static void add_sign_and_pad(char *dst, size_t len_s, size_t len_pad)
// {
//     char    *shift_sign_and_pad;
//     char    *next_to_sign;
//     size_t  absolute_val;
//     size_t  num_padding;

//     shift_sign_and_pad = &dst[len_pad + 2];
//     next_to_sign = &dst[1];
//     absolute_val = len_s - 1;
//     num_padding = len_pad + 1;
//     ft_memmove(shift_sign_and_pad, next_to_sign, absolute_val);
//     ft_memset(next_to_sign, '0', num_padding);
//     dst[0] = '-';
// }

// static void paddig_zero(char *dst, size_t len_s, size_t len_pad)
// {
//     ft_memmove(&dst[len_pad], dst, len_s);
//     ft_memset(dst, '0', len_pad);
// }