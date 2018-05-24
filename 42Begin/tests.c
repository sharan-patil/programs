#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);

int	main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	char str1[50] = "waow nitin is awesome!";
	char str2[50] = "dumb!";
	char *son;
	printf("Memset test:\n");
	printf("Before: %s\n", str);
	son = ft_memset(str, '.', 8*sizeof(char));
	printf("After: %s\n", str);
	printf("Returned Value: %s\n", son);
	char *son2;
	printf("-------------\n");
	printf("Bzero test: \n");
	printf("Before: %s\n", str);
	ft_bzero(str, 8*sizeof(char));
	printf("After: %s\n", str);
	printf("-------------\n");
	printf("Memcpy test:\n");
	printf("Before: %s\n", str1);
	son2 = ft_memcpy(str1, str2, 5);
	printf("After: %s\n", str1);
	printf("Returned Value: %s\n", son2);
	char str3[50] = "GeeksForGeeks is for programming geeks.";
	char str4[50] = "waow nitin is awesome!";
	printf("-------------\n");
	printf("Memccpy test:\n");
	printf("Before: %s\n", str4);
	memccpy(str4, str3, 's', 10);
	printf("After: %s\n", str4);
	char str5[50] = "GeeksForGeeks is for programming geeks.";
	char str6[50] = "waow nitin is awesome!";
	printf("-------------\n");
	printf("ft_Memccpy test:\n");
	printf("Before: %s\n", str6);
	ft_memccpy(str6, str5, 's', 10);
	printf("After: %s\n", str6);
	char new1[20] = "Everyday..";
	char *bro;
	printf("-------------\n");
	printf("memchr:\n");
	printf("Before: %s\n", new1);
	bro = memchr(new1, 'y', 10);
	printf("After: %s\n", new1);
	printf("%c\n", *bro);
	char new2[20] = "Everyday..";
	char *bro2;
	printf("-------------\n");
	printf("ft_memchr:\n");
	printf("Before: %s\n", new2);
	bro2 = ft_memchr(new2, 'y', 10);
	printf("After: %s\n", new2);
	printf("%c\n", *bro2);
	printf("-------------\n");
	char key1[10] = "abcde";
	char key2[10] = "abcdf";
	int wew;
	printf("memcmp test:\n");
	printf("String1: %s | String2: %s\n", key1, key2);
	wew = memcmp(key1, key2, 5);
	printf("Returned Value: %d\n", wew);
	char key3[10] = "abcde";
	char key4[10] = "abcdf";
	printf("-------------\n");
	printf("ft_memcmp test:\n");
	printf("String1: %s | String2: %s\n", key3, key4);
	wew = ft_memcmp(key3, key4, 5);
	printf("Returned Value: %d\n", wew);
	printf("-------------\n");
	printf("strlen test:\n");
	printf("String: \"lmao\"\n");
	char pop[10] = "lmao";
	int count = ft_strlen(pop);
	printf("Returned Value: %d\n", count);
	printf("-------------\n");
	printf("ft_strdup test: \n");
	printf("String: \"lmao\"\n");
	char name1[10] = "lmao";
	char *name2;
	name2 = ft_strdup(name1);
	printf("Returned Value: %s", name2);
	return (0);
}
