#include "ft_printf.h"

char	*convert_uint(uint32_t n, int base)
{
	char	*to_a;
	size_t	len;

	len = long_count_length(n, base);
	to_a = long_to_char(n, 1, len, base);
	return (to_a);
}

char	*convert_di(int n, int *flag)
{
	char	*to_a;
	size_t	len;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		*flag |= FLAG_NEGA;
	}
	len = long_count_length(n, 10);
	to_a = long_to_char(n, sign, len, 10);
	return (to_a);
}

char	*convert_p(void *s)
{
	uint64_t    n;
	char		*to_a;
	size_t	    len;
    char        *ret;

	n = (uint64_t)s;
	len = uint64t_count_length(n, 16);
	to_a = uint64t_to_char(n, len, 16);
    ret = ft_strjoin("0x", to_a);
    if (ret == NULL)
        return (NULL);
    free(to_a);
	return (ret);
}

char	*convert_x(uint32_t n, int base)
{
	char	*to_a;
	size_t	len;

	len = long_count_length(n, base);
	to_a = long_to_char(n, 1, len, base);
	return (to_a);
}