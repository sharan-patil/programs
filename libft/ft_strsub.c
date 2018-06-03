#include <libft.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;
	unsigned int i;
	new = (char*)malloc(len + 1);
	i = 0;
	while (s[i] != '\0')
	{
		if (i >= start && i < len)
			new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
