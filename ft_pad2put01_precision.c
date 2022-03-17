#include "ft_printf.h"

size_t	pad_precision(char *alc_cp, size_t len_s, size_t prec_w, int b_flag)
{
	if (is_diux_flag(b_flag) == 1)
		len_s = pad_precision_digit(alc_cp, len_s, prec_w, b_flag);
	if (len_s > prec_w && (b_flag & FLAG_S) && (b_flag & FLAG_IS_PREC))
	{
		len_s = prec_w;
		ft_strlcpy(alc_cp, alc_cp, len_s + 1);
	}
	return (len_s);
}

size_t	pad_precision_digit(char *alc_cp, size_t len_s, size_t prec_w, int b_flag)
{
	size_t	pad_w;

	pad_w = 0;
	if (len_s <= prec_w && (b_flag & FLAG_IS_PREC))
	{
		pad_w = prec_w - len_s;
		if (b_flag & FLAG_NEGA)
		{
			ft_memmove(&alc_cp[pad_w + 2], &alc_cp[1], len_s - 1);
			ft_memset(&alc_cp[1], '0', pad_w + 1);
			alc_cp[0] = '-';
		}
		else
		{
			ft_memmove(&alc_cp[pad_w], alc_cp, len_s);
			ft_memset(alc_cp, '0', pad_w);
		}
        if (b_flag & FLAG_HASH)
		{
			ft_memmove(&alc_cp[2], alc_cp, prec_w);
			ft_memmove(alc_cp, "0x", 2);
		}
		len_s = prec_w;
	}
	return (len_s);
}
