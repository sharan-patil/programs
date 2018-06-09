#include <libft.h>

char	*ft_strnstr(const char* haystack, const char* needle, size_t n)
{
	int i, j, len_n, temp;
	i = 0;
	len_n = ft_strlen(needle);
	if (len_n == 0)
		return ((char*)&haystack[0]);
	while (haystack[i] != '\0' && i + 1 < (int)n)
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
				if (i + j > (int)n)
					return (NULL);
			}
		}
		i++;
	}
	return (NULL);
}
