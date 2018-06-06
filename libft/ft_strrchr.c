#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int len, i;
	len = ft_strlen(s);
	i = len;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
