#include "ft_printf.h"

char	*convert_c(unsigned char c)
{
	char	*conv_s;

	conv_s = ft_strdup(" ");
	if (conv_s == NULL)
		return (NULL);
	conv_s[0] = c;
	return (conv_s);
}

char	*convert_s(char *s)
{
	char	*conv_s;

    if (ft_strlen(s) > INT_MAX)
        return (NULL);
	conv_s = NULL;
	if (s == NULL)
		conv_s = ft_strdup("(null)");
	else
		conv_s = ft_strdup(s);
	if (conv_s == NULL)
		return (NULL);
	return (conv_s);
}