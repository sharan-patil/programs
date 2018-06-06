#include <libft.h>

char	*ft_strnew(size_t size)
{
	char *new;
	new = (char*)malloc(size);
	return (ft_memset(new, '\0', size));
}
