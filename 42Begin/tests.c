#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

int	main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	char str1[50] = "waow nitin is awesome!";
	char str2[50] = "dumb!";
	printf("Memset test:\n");
	printf("Before: %s\n", str);
	ft_memset(str+13, '.', 8*sizeof(char));
	printf("After: %s\n", str);
	printf("Bzero test: \n");
	printf("Before: %s\n", str);
	ft_bzero(str+13, 8*sizeof(char));
	printf("After: %s\n", str);
	printf("Memcpy test:\n");
	printf("Before: %s\n", str1);
	ft_memcpy(str1 + 14, str2, 5);
	printf("After: %s\n", str1);
	return (0);
}
