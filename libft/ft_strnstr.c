#include <libft.h>

char	*ft_strnstr(const char* haystack, const char* needle, size_t n)
{
	int i, j, len_n, temp;
	i = 0;
	len_n = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] != '\0' && (unsigned int)i < n)
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
					return ((char*)&haystack[i - len_n]);
			}
			continue ;
		}
		i++;
	}
	return (NULL);
}
