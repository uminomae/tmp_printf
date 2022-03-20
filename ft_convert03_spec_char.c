#include "ft_printf.h"

char	*convert_c(unsigned char c)
{
	char	*conv_str;

	conv_str = (char *)malloc(sizeof(char) * 2);
    if (conv_str == NULL)
        return (NULL);
	conv_str[0] = c;
    conv_str[1] = '\0';
	return (conv_str);
}

char	*convert_s(char *s)
{
	char	*conv_str;

    if (ft_strlen(s) > INT_MAX)
        return (NULL);
	conv_str = NULL;
	if (s == NULL)
        return (ft_strdup("(null)"));
	else
        return (ft_strdup(s));
}