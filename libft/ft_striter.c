#include <libft.h>

void	ft_striter(char *s, void (*f)(char *s))
{
	int i;
	i = 0;
	if (!s)
		return ;
	while(s[i] != '\0')
	{
		f(&s[i]);
		i++;
	}
}
