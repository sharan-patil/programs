#include <libft.h>

char	*ft_strtrim(char const *s)
{
	int i, j, len_s, count;
	char *new;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	j = len_s - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == len_s && i != 0)
	{
		new = (char*)malloc(1);
		*new = '\0';
		return (new);
	}
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	new = (char*)malloc(j - i + 2);
	if (!new)
		return (NULL);
	count = i;
	i = 0;
	while (count <= j)
	{
		new[i] = s[count];
		count++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
