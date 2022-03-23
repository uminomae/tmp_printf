#include "ft_printf.h"

static size_t write_field_width(char *put_str, int flag, size_t field);

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

int  write_put_str(char *put_str, int flag, size_t field)
{
    size_t len_str;

    len_str = ft_strlen(put_str);
    if (len_str > (size_t)INT_MAX)
    {
        free(put_str);
        return (-1);
    }
    else if (flag & FLAG_C0)
        len_str = write_field_width(put_str, flag, field);
    else
        write(1, put_str, len_str);
    free (put_str);
    return (len_str);
}

static size_t write_field_width(char *put_str, int flag, size_t field)
{
    if (flag & FLAG_IS_FIELD)
        write(1, put_str, field);
    else
    {
        write(1, "\0", 1);
        free (put_str);
        return (1);
    }
    return (field);
}