#include <libft.h>

int	ft_strlen(const char *s)
{
	int i;
	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return(i);
}
