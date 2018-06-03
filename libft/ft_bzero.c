#include <libft.h>

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
