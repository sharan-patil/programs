#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	i = 1;
	char *n1, *n2;
	n1 = (char*) s1;
	n2 = (char*) s2;
	while (i <= n)
	{
		if (*n1 == *n2)
		{
			n1++;
			n2++;
		}
		else
		{
			return ((int)*n1 - (int)*n2);
		}
		i++;
	}
	return ('\0');
}
