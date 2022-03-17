#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

# define GET_FIELD      0x00000000ffffffff //GET LOW 32

# define FLAG_HASH      0x00001  //(1<<0)
# define FLAG_HYPHEN    0x00002  //(1<<1)
# define FLAG_PLUS      0x00004  //(1<<2)
# define FLAG_SPACE     0x00008  //(1<<3)
# define FLAG_ZERO      0x00010  //(1<<4)

# define FLAG_NEGA      0x00020  //(1<<5)
# define FLAG_IS_PREC   0x00040  //(1<<6)
# define FLAG_IS_FIELD  0x00080  //(1<<7)

# define FLAG_C         0x00100  //(1<<8)
# define FLAG_S         0x00200  //(1<<9)
# define FLAG_P         0x00400  //(1<<10)
# define FLAG_D         0x00800  //(1<<11)
# define FLAG_I         0x01000  //(1<<12)
# define FLAG_U         0x02000  //(1<<13)
# define FLAG_X         0x04000  //(1<<14)
# define FLAG_LX        0x08000  //(1<<15)

# define FLAG_C0        0x10000  //(1<<16)

int		ft_printf(const char *fmt, ...);
size_t	get_option_flag(const char *fmt, int *b_flag);
void	get_spec_flag(const char *fmt, int *b_flag);
int		is_diux_flag(int b_flag);
size_t	get_prec_w(const char *fmt, long long *b_width, int *b_flag);
size_t	get_field_w(const char *fmt, long long *b_width, int *b_flag);
int     cnvrt_ap_to_output(const char *fmt, va_list *ap, size_t *i);
char	*convert_c(unsigned char c);
char	*convert_s(char *s);
char	*convert_uint(unsigned int n, int base);
char	*to_upper_str(char *toa);
char	*convert_di(int n, int *b_flag);
char	*convert_p(void *s);
int		long_count_dig(long n, int base);
char	*long_to_char(long n, int sign, size_t dig, int base);
int		ull_count_dig(unsigned long long n, int base);
char	*ull_to_char(unsigned long long n, int sign, size_t dig, int base);
int     put_with_pad_ap(char *conv_s, int b_flag, size_t field_w, size_t prec_w);
size_t	pad_precision(char *alc_cp, size_t len_s, size_t prec_w, int b_flag);
size_t  add_fmt_option(char *str, size_t len, int b_flag);
void	pad_field(char *str, size_t len, size_t shift, int b_flag);
int     write_put_str(char *put_str, int b_flag, size_t field_w, size_t len_put_s);


#endif
