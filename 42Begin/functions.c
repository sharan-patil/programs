#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int i;
	char *temp;
	temp = s;
	i = 1;
	while (i <= n)
	{
		*temp = c;
		i++;
		temp++;
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

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *des, *sour;
	size_t i;
	i = 1;
	des = dest;
	sour = src;
	while (i <= n)
	{
		*des = *sour;
		i++;
		des++;
		sour++;
	}
	return (dest);
}
