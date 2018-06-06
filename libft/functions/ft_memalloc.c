#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void *space;
	space = malloc(size);
	ft_bzero(space, size);
	return (space);
}
