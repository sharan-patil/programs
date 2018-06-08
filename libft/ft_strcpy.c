#include <libft.h>

char	*ft_strcpy(char *dest, const char *src)
{
	int i, len_src;
	i = 0;
    len_src = ft_strlen(src);
	while (i < len_src)
	{
        dest[i] = src[i];
        i++;
	}
    dest[i] = '\0';
	return (&dest[0]);
}
