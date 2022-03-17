#include "ft_printf.h"

int  write_put_str(char *put_str, int b_flag, size_t field_w, size_t len_put_s)
{
    if (len_put_s < 0 || len_put_s > (size_t)INT_MAX)
    {
        free(put_str);
        return (-1);
    }
    if (b_flag & FLAG_C0)
    {
        if (b_flag & FLAG_IS_FIELD)
        {
            write(1, put_str, field_w);
            len_put_s = field_w;
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
