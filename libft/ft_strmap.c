#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *new;
	int i;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	new = (char *)malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
