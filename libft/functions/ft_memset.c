#include <libft.h>

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
