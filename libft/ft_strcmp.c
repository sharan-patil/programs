#include <libft.h>

int	ft_strcmp(const char* s1, const char* s2)
{
	int i, len;
	i = 0;
	len = ft_strlen(s1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (ft_strlen(s1) - ft_strlen(s2));
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
