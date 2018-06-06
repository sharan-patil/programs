#include <libft.h>

char	*ft_strcpy(char *dest, const char *src)
{
	int i;
	i = 0;
	while (*src != '\0')
	{
		*dest = (char)*src;
		dest++;
		src++;
		i++;
	}
	while (i != 0)
	{
		dest--;
		i--;
	}
	return (dest);
}
