#include <libft.h>

int	ft_strnequ(char const *s1, char const *s2, size_t size)
{
	int i;
	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while ((unsigned int)i < size)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
