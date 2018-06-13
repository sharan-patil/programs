#include <libft.h>

void	ft_putendl(char const *s)
{
	int i;
	char hmm;
	hmm = '\n';
	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, &hmm, 1);
}
