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
	while (i != 0)
	{
		news--;
		i--;
	}
	return (news);
}
