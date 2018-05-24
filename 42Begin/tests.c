#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

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
	char str3[50] = "GeeksForGeeks is for programming geeks.";
	char str4[50] = "waow nitin is awesome!";
	printf("Memccpy test:\n");
	printf("Before: %s\n", str4);
	memccpy(str4, str3, 's', 10);
	printf("After: %s\n", str4);
	char str5[50] = "GeeksForGeeks is for programming geeks.";
	char str6[50] = "waow nitin is awesome!";
	printf("ft_Memccpy test:\n");
	printf("Before: %s\n", str6);
	ft_memccpy(str6, str5, 's', 10);
	printf("After: %s\n", str6);
	return (0);
}
