#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i;
	char *new;
	i = 0;
	while (s[i] != '\0')
		i++;
	new = (char*)malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] =  f((unsigned int)i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
