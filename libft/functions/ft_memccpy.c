#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;
	char *dest = dst;
	char *l;
	i = 1;
	l = (char*) src;
	while (i <= n && (int) *l != c)
	{
		*dest = *l;
		i++;
		dest++;
		l++;
	}
	if ((int) *l == c)
	{
		*dest = *l;
		return (dest);
	}
	return (NULL);
}
