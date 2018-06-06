#include <libft.h>

char	*ft_strtrim(char const *s)
{
	int i, j;
	char *new;
	new = (char*)malloc(ft_strlen(s) + 1);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		new[i] = s[i];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
