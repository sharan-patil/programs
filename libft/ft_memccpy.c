#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;
	char *dest;
	i = 0;
	dest = (char*)dst;
	while (i < n)
	{
		*(dest + i) = *((unsigned char*)src + i);
		if (*((unsigned char*)src + i) == (unsigned char)c)
		{
			*(dest + i) = *((unsigned char*)src + i);
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
