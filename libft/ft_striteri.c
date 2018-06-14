#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;
	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f((unsigned int)i, &s[i]);
		i++;
	}
}
