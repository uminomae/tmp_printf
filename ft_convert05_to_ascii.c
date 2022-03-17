#include "ft_printf.h"

int	long_count_dig(long n, int base)
{
	size_t	dig;

	dig = 0;
	if (n <= 0)
		dig = 1;
	while (n != 0)
	{
		n /= base;
		dig++;
	}
	return (dig);
}

char	*long_to_char(long n, int sign, size_t dig, int base)
{
	char	*toa;
	size_t	i;
	size_t	j;

	toa = (char *)ft_calloc(1, sizeof(char) * (dig + 1));
	if (toa == NULL)
		return (NULL);
	i = 0;
	j = dig - 1;
	while (i < dig)
	{
		if (n == 0 && sign < 0)
			toa[0] = '-';
		else
		{
			toa[j] = n % base * sign + '0';
			if (toa[j] > 57)
				toa[j] += 39;
		}
		n /= base;
		i++;
		j--;
	}
	return (toa);
}

int	ull_count_dig(unsigned long long n, int base)
{
	size_t	dig;

	dig = 0;
	if (n <= 0)
		dig = 1;
	while (n != 0)
	{
		n /= base;
		dig++;
	}
	return (dig);
}

char	*ull_to_char(unsigned long long n, int sign, \
		size_t dig, int base)
{
	char	*toa;
	size_t	i;
	size_t	j;

	toa = (char *)ft_calloc(1, sizeof(char) * (dig + 1));
	if (toa == NULL)
		return (NULL);
	i = 0;
	j = dig - 1;
	while (i < dig)
	{
		if (n == 0 && sign < 0)
			toa[0] = '-';
		else
		{
			toa[j] = n % base * sign + '0';
			if (toa[j] > 57)
				toa[j] += 39;
		}
		n /= base;
		i++;
		j--;
	}
	return (toa);
}
