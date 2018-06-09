#include <libft.h>

char	*ft_strnew(size_t size)
{
	char *new;
	new = (char*)malloc(size + 1);
	if (!new)
		return (NULL);
	return (ft_memset(new, '\0', size + 1));
}
