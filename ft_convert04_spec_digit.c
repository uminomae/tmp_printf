#include "ft_printf.h"

char	*to_upper_str(char *to_a)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(to_a);
	i = 0;
	while (i < len)
	{
		to_a[i] = ft_toupper(to_a[i]);
		i++;
	}
	return (to_a);
}

char	*convert_uint(unsigned int n, int base)
{
	char	*to_a;
	size_t	dig;

	dig = long_count_dig(n, base);
	to_a = long_to_char(n, 1, dig, base);
	return (to_a);
}

char	*convert_di(int n, int *bit_flag)
{
	char	*to_a;
	size_t	dig;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		*bit_flag |= FLAG_NEGA;
	}
	dig = long_count_dig(n, 10);
	to_a = long_to_char(n, sign, dig, 10);
	return (to_a);
}

char	*convert_p(void *s)
{
	unsigned long long	n;
	char				*to_a;
	size_t				dig;

	n = (unsigned long long)s;
	dig = ull_count_dig(n, 16);
	to_a = ull_to_char(n, 1, dig, 16);
	ft_memmove(&to_a[2], to_a, ft_strlen(to_a));
	ft_memmove(to_a, "0x", 2);
	return (to_a);
}
