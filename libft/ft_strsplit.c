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
	// new = (char**)malloc(ft_strlen(s) * sizeof(char*));
	// if (!new)
	// 	return (NULL);
	// while (1)
	// {
	// 	while (s[i] == c)
	// 		i++;
	// 	while (s[i] != c && s[i] != '\0')
	// 	{
	// 		i++;
	// 		q++;
	// 	}
	// 	new[p] = (char*)malloc(q + 1);
	// 	count = 0;
	// 	while (count <= q - 1)
	// 	{
	// 		new[p][count] = s[i - q + count];
	// 		count++;
	// 	}
	// 	new[p][count] = '\0';
	// 	q = 0;
	// 	p++;
	// 	if (s[i] == '\0')
	// 		break ;
	// }
	// return (new);
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
	i = 1;
	q = 0;
	p = 0;
	count = 0;
	while (i < points[0][0])
	{
		new[i - 1] = (char*)malloc(points[i][1] + 1);
		while (count < points[i][1])
		{
			new[i - 1][count] = s[(points[i][0] + count)];
			count++;
		}
		new[i - 1][count] = '\0';
		count = 0;
		i++;
	}
	return (new);
}
