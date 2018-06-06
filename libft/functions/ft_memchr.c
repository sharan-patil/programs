#include <libft.h>

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
