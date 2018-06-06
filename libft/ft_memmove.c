#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *des, *sour, *temp;
	size_t i;
	temp = (char*)malloc(ft_strlen(src) + 1);
	i = -1;
	des = dest;
	sour = (char *) src;
	while (++i < n)
		temp[i] = sour[i];
	i = -1;
	while (++i < n)
		des[i] = temp[i];
	free(temp);
	return (dest);
}
