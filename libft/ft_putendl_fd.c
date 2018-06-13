#include <libft.h>

void	ft_putendl_fd(char const *c, int fd)
{
	int i;
	char hmm;
	hmm = '\n';
	i = 0;
	if (!c)
		return ;
	while(c[i] != '\0')
	{
		write(fd, &c[i], 1);
		i++;
	}
	write(fd, &hmm, 1);
}
