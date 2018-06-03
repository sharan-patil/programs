#include <libft.h>

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	i = 0;
	while (*dest != '\0')
	{
		i++;
		dest++;
	}
	while (*src != '\0')
	{
		i++;
		*dest = (char)*src;
		dest++;
		src++;
	}
	i++;
	*dest = '\0';
	while (i != 1)
	{
		dest--;
		i--;
	}
	return (dest);
}
