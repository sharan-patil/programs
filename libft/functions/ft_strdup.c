#include <libft.h>

char	*ft_strdup(const char *s1)
{
	size_t len;
	char *news;
	int i;
	i = 0;
	len = sizeof(*s1);
	news = (char*)malloc(len);
	while (*s1 != '\0')
	{
		*news = (char)*s1;
		news++;
		s1++;
		i++; 
	}
	*news = '\0';
	news++;
	while (i != -1)
	{
		news--;
		i--;
	}
	return (news);
}
