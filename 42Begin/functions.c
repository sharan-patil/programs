#include <string.h>
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;
	char *temp;
	temp = s;
	i = 1;
	while (i <= n)
	{
		*temp = c;
		i++;
		temp++;
	}
	i = 1;
	while (i <= n)
	{
		temp--;
		i++;
	}
	return (temp);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int i = 1;
	char *temp;
	temp = s;
	while (i <= n)
	{
		*temp = 0;
		i++;
		temp++;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *des, *sour;
	size_t i;
	i = 1;
	des = dest;
	sour = (char *) src;
	while (i <= n)
	{
		*des = *sour;
		i++;
		des++;
		sour++;
	}
	return (dest);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;
	char *dest = dst;
	char *l;
	i = 1;
	l = (char*) src;
	while (i <= n && (int) *l != c)
	{
		*dest = *l;
		i++;
		dest++;
		l++;
	}
	if ((int) *l == c)
	{
		*dest = *l;
		return (dest);
	}
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *des, *sour;
	size_t i;
	i = 1;
	des = dest;
	sour = (char *) src;
	while (i <= n)
	{
		*des = *sour;
		i++;
		des++;
		sour++;
	}
	return (dest);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *new;
	new = (char *) s;
	size_t i;
	i = 1;
	while (i <= n)
	{
		if (*new == (char) c)
		{
			return (new);
		}
		i++;
		new++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	i = 1;
	char *n1, *n2;
	n1 = (char*) s1;
	n2 = (char*) s2;
	while (i <= n)
	{
		if (*n1 == *n2)
		{
			n1++;
			n2++;
		}
		else
		{
			return ((int)*n1 - (int)*n2);
		}
		i++;
	}
	return ('\0');
}

int	ft_strlen(const char *s)
{
	int i;
	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return(i);
}

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

char	*ft_strcpy(char *dest, const char *src)
{
	int i;
	i = 0;
	while (*src != '\0')
	{
		*dest = (char)*src;
		dest++;
		src++;
		i++;
	}
	while (i != 0)
	{
		dest--;
		i--;
	}
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for(; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	i = 0;
	while (*dest != '\0')
	{
		i++;
		dest++;
	}
	while (*src != '\0')
	{
		i++;
		*dest = (char)*src;
		dest++;
		src++;
	}
	i++;
	*dest = '\0';
	while (i != 1)
	{
		dest--;
		i--;
	}
	return (dest);
}

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len_d = ft_strlen(dest);
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[len_d + i] = src[i];
	dest[len_d + i] = '\0';
	return (dest);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int i, len_d;
	i = 0;
	len_d = ft_strlen(dest);
	while (i < (int)size - len_d - 1)
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[ft_strlen(dest) + i] = '\0';
	return (len_d + ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int len, i;
	len = ft_strlen(s);
	i = len;
	while (i != 0)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}

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

char	*ft_strnstr(const char* haystack, const char* needle, size_t n)
{
	int i, j, len_n;
	i = 0;
	len_n = ft_strlen(needle);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (j < len_n && j < (int)n)
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

int	ft_strcmp(const char* s1, const char* s2)
{
	return (ft_strlen(s1) - ft_strlen(s2));
}

int	ft_strncmp(const char* s1, const char* s2, size_t n)
{
	size_t i;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(const char* s)
{
	int i, n, j, positive, c, ans;
	c = 0;
	j = 1;
	i = 0;
	n = 0;
	ans = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
	{
		i++;
	}		
	if (s[i] == '-')
	{
		positive = 0;
		i++;
	}
	if (s[i] == '+')
	{
		positive = 1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		n = (j * (s[i] - 48)) + n;
		j *= 10;
		i++;
		c++;
	}
	j /= 10;
	while (n != 0)
	{
		ans = ((n % 10) * j) + ans;
		j /= 10;
		n = n / 10;
	}
	if (positive == 0)
		ans *= -1;
	return (ans);
}

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
