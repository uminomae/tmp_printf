#include "ft_printf.h"

static char	    *get_alc_size(char *conv_s, int b_flag, size_t field_w, size_t prec_w);

int	put_with_pad_ap(char *conv_s, int b_flag, size_t field_w, size_t prec_w)
{
	char	*put_str;
	size_t	len_s;
    size_t	len_put_s;
    size_t  len_write_put;

	put_str = get_alc_size(conv_s, b_flag, field_w, prec_w);
    if (put_str == NULL)
        return (-1);
	len_s = ft_strlen(conv_s);
	ft_memmove(put_str, conv_s, len_s);
	len_s = pad_precision(put_str, len_s, prec_w, b_flag);
	len_s = add_fmt_option(put_str, len_s, b_flag);
	if (len_s < field_w && (b_flag & FLAG_IS_FIELD))
		pad_field(put_str, len_s, field_w, b_flag);
	if (b_flag & FLAG_LX)
		put_str = to_upper_str(put_str);
    len_put_s = ft_strlen(put_str);
    len_write_put = write_put_str(put_str, b_flag, field_w, len_put_s);
	return (len_write_put);
}

static char	*get_alc_size(char *conv_s, int b_flag, size_t field_w, size_t prec_w)
{
	size_t	len_s;
	char	*alc_cp;

	len_s = ft_strlen(conv_s);
	if (len_s < prec_w && !(b_flag & FLAG_S) && (b_flag & FLAG_IS_PREC))
		len_s = prec_w;
	else if (len_s > prec_w && b_flag & FLAG_S && (b_flag & FLAG_IS_PREC))
		len_s = prec_w;
	if (len_s < field_w && (b_flag & FLAG_IS_FIELD))
		len_s = field_w;
	if ((b_flag & FLAG_NEGA))
		len_s += 1;
	if (b_flag & FLAG_HASH)
	{
		if (b_flag & FLAG_X || b_flag & FLAG_LX)
			len_s += 2;
	}
	if (b_flag & FLAG_PLUS || b_flag & FLAG_SPACE)
	{
		if (b_flag & FLAG_D || b_flag & FLAG_I)
			len_s += 1;
	}
	alc_cp = (char *)ft_calloc(1, len_s + 1);
	return (alc_cp);
}

int	is_diux_flag(int b_flag)
{
	if (b_flag & FLAG_D || b_flag & FLAG_I)
		return (1);
	if (b_flag & FLAG_U || b_flag & FLAG_X || b_flag & FLAG_LX)
		return (1);
	return (0);
}