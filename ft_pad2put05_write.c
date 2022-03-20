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

int  write_put_str(char *put_str, int flag, size_t field, size_t len_put_s)
{
    if (len_put_s > (size_t)INT_MAX)
    {
        free(put_str);
        return (-1);
    }
    if (flag & FLAG_C0)
    {
        if (flag & FLAG_IS_FIELD)
        {
            write(1, put_str, field);
            len_put_s = field;
        }
        else
        {
            write(1, "\0", 1);
            free (put_str);
            return (1);
        }
    }
    else
        write(1, put_str, len_put_s);
    free (put_str);
    return (len_put_s);
}
