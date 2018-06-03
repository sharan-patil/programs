#include <libft.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int i, len_d;
	i = 0;
	len_d = ft_strlen(dest);
	while (i < (int)size - len_d - 1)
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[ft_strlen(dest) + i] = '\0';
	return (len_d + ft_strlen(src));
}
