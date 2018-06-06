#include <libft.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;
	unsigned int i, j;
	new = (char*)malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && i < len + (int)start)
		{	
			new[j] = s[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (&new[0]);
}
