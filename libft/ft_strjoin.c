#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int len1, i, len2;
	char *new;
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char*)malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	while(i < len1 + len2)
	{
		if (i < len1)
			new[i] = s1[i];
		else
			new[i] = s2[i - len1];
		i++;
	}
	new[i] = '\0';
	return (new);
}
