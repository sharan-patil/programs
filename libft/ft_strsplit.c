#include <libft.h>

char	**ft_strsplit(char const *s, char c)
{
	char **new;
	int i, p, q, count;
	int points[100][2];
	p = 1;
	q = 0;
	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		points[p][q] = i;
		q++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			count++;
		}
		points[p][q] = count;
		p++;
		q = 0;
		count = 0;
	}
	points[0][0] = p;
	new = (char**)malloc(sizeof(char*) * points[0][0]);
	if (!new)
		return (NULL);
	i = 1;
	q = 0;
	p = 0;
	count = 0;
	while (i < points[0][0])
	{
		new[i - 1] = (char*)malloc(sizeof(char) * (points[i][1] + 1));
		if (!new[i - 1])
			return (NULL);
		while (count < points[i][1])
		{
			new[i - 1][count] = s[(points[i][0] + count)];
			count++;
		}
		new[i - 1][count] = '\0';
		count = 0;
		i++;
	}
	new[i - 1] = NULL;
	return (new);
}
