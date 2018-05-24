#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;
	char *temp;
	temp = s;
	i = 1;
	while (i <= n)
	{
		*temp = c;
		i++;
		temp++;
	}
	i = 1;
	while (i <= n)
	{
		temp--;
		i++;
	}
	return (temp);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int i = 1;
	char *temp;
	temp = s;
	while (i <= n)
	{
		*temp = 0;
		i++;
		temp++;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *des, *sour;
	size_t i;
	i = 1;
	des = dest;
	sour = (char *) src;
	while (i <= n)
	{
		*des = *sour;
		i++;
		des++;
		sour++;
	}
	return (dest);
}

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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *des, *sour;
	size_t i;
	i = 1;
	des = dest;
	sour = (char *) src;
	while (i <= n)
	{
		*des = *sour;
		i++;
		des++;
		sour++;
	}
	return (dest);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *new;
	new = (char *) s;
	size_t i;
	i = 1;
	while (i <= n)
	{
		if (*new == (char) c)
		{
			return (new);
		}
		i++;
		new++;
	}
	return (NULL);
}
