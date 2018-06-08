#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;
	char *dest = dst;
	unsigned char *l;
	i = 1;
	l = (unsigned char*) src;
	while (i <= n && *l != (unsigned char)c)
	{
		*dest = (char)*l;
		i++;
		dest++;
		l++;
	}
	if (*l == (unsigned char)c)
	{
		*dest = (char)*l;
        dest++;
		return (dest);
	}
	return (NULL);
}
