#include <libft.h>

char	*ft_strstr(const char* haystack, const char* needle)
{
	int i, j, len_n, temp;
	i = 0;
	len_n = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			temp = i;
			while (j < len_n)
			{
				if (haystack[temp] != needle[j])
					break ;
				j++;
				temp++;
				if (j == len_n)
					return ((char*)&haystack[temp - len_n]);
			}
			i++;
			continue ;
		}
		i++;
	}
	return (NULL);
}
