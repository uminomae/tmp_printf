#include "ft_printf.h"

char	*get_alloc_size(char *conv_str, int flag, size_t field, size_t prec)
{
	size_t	len_s;
	char	*alloc_cp;

	len_s = ft_strlen(conv_str);
	if (len_s < prec && !(flag & FLAG_S) && (flag & FLAG_IS_PREC))
		len_s = prec;
	else if (len_s > prec && flag & FLAG_S && (flag & FLAG_IS_PREC))
		len_s = prec;
	if (len_s < field && (flag & FLAG_IS_FIELD))
		len_s = field;
	if ((flag & FLAG_NEGA))
		len_s += 1;
	if (flag & FLAG_NUMBER_SIGN)
	{
		if (flag & FLAG_X || flag & FLAG_LX)
			len_s += 2;
	}
	if (flag & FLAG_PLUS || flag & FLAG_SPACE)
	{
		if (flag & FLAG_D || flag & FLAG_I)
			len_s += 1;
	}
	alloc_cp = (char *)ft_calloc(1, len_s + 1);
	return (alloc_cp);
}