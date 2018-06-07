#include <libft.h>

void	*ft_memalloc(size_t size)
{
	char *space;
	space = (char*)malloc(size);
	if (!space)
		return (NULL);
	ft_bzero(space, size);
	return (space);
}
