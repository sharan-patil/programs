char	*ft_strstr(const char* haystack, const char* needle)
{
	int i, j, len_n;
	i = 0;
	len_n = ft_strlen(needle);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (j < len_n)
			{
				if (haystack[i] != needle[j])
					break ;
				j++;
				i++;
				if (j == len_n)
					return ((char*)&haystack[i - len_n]);
			}
			continue ;
		}
		i++;
	}
	return (NULL);
}
