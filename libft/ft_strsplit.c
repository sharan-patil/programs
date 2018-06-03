#include <libft.h>

char	**ft_strsplit(char const *s, char c)
{
	char **new;
	int i, p, q;
	p = 0;
	q = 0;
	i = 0;
	new = (char**)malloc(ft_strlen(s));
	while (1)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			new[p][q] = s[i];
			i++;
			q++;
		}
		p++;
		if (s[i] == '\0')
			break ;
	}
	return (new);
}
