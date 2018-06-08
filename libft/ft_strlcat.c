#include <libft.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i, len_d;
	i = 0;
	len_d = ft_strlen(dest);
	while (i < size - len_d - 1 && src[i] != '\0')
	{
		dest[len_d + i] = src[i];
		i++;
	}
   // printf("len_d: %d i: %d\n", len_d, i);
	dest[len_d + i] = '\0';
	return (len_d + ft_strlen(src));
}
