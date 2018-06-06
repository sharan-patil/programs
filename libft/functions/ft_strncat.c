#include <libft.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len_d = ft_strlen(dest);
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[len_d + i] = src[i];
	dest[len_d + i] = '\0';
	return (dest);
}
