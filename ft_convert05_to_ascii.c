#include "ft_printf.h"

int long_count_length(long n, int base)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char    *long_to_char(long n, int sign, size_t len, int base)
{
	char	*to_a;
	size_t	i;
	size_t	j;

	to_a = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (to_a == NULL)
		return (NULL);
	i = 0;
	j = len - 1;
	while (i < len)
	{
        to_a[j] = "0123456789abcdef"[n % base * sign];
		if (n == 0 && sign == -1)
			to_a[0] = '-';
		n /= base;
		i++;
		j--;
	}
	return (to_a);
}

int uint64t_count_length(uint64_t n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char    *uint64t_to_char(uint64_t n, size_t len, int base)
{
	char	*to_a;
	size_t	i;
	size_t	j;

	to_a = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (to_a == NULL)
		return (NULL);
	i = 0;
	j = len - 1;
	while (i < len)
	{
        to_a[j] = "0123456789abcdef"[n % base];
		n /= base;
		i++;
		j--;
	}
	return (to_a);
}