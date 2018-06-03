#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strncpy(char *dest, const char *src, size_t n);

char	*ft_strcat(char *dest, const char *src);

char	*ft_strncat(char *dest, const char *src, size_t n);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

char	*ft_strstr(const char* haystack, const char* needle);

char	*ft_strnstr(const char* haystack, const char* needle, size_t n);

int	ft_strcmp(const char* s1, const char* s2);

int	ft_strncmp(const char* s1, const char* s2, size_t n);

int	ft_atoi(const char* s);

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);

int	ft_isascii(int c);

int	ft_isprint(int c);

int	ft_toupper(int c);

int	ft_tolower(int c);

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
	printf("ft_strlen test:\n");
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
	printf("Returned Value: %s\n", name2);
	printf("-------------\n");
	printf("ft_strcpy test:\n");
	printf("string = think\n");
	char think[6] = "think";
	char think2[6];
	char think3[6];
	printf("Returned Value: %s\n", ft_strcpy(think2, think));
	printf("Second string: %s\n", think2);
	printf("-------------\n");
	printf("ft_strncpy test:\n");
	printf("string: think and n = 3\n");
	printf("Returned Value: %s\n", ft_strncpy(think3, think, 3));	
	printf("second string: %s\n", think3);
	printf("-------------\n");
	printf("strcat test:\n");
	printf("string1 = lmao & string2 = hmm\n");
	char box1[10] = "lmao";
	char box2[10] = "hmm";
	printf("Returned Value: %s\n", strcat(box1, box2));
	printf("string: %s\n", box1);
	printf("-------------\n");
	printf("ft_strcat test:\n");
	printf("string1 = lmao & string2 = hmm\n");
	char box3[10] = "lmao";
	char box4[10] = "hmm";
	printf("Returned Value: %s\n", ft_strcat(box3, box4));
	printf("string: %s\n", box3);
	printf("-------------\n");
	printf("ft_strncat test: \n");
	char box5[10] = "lmao";
	char box6[10] = "hmm";
	printf("string1 = lmao & string2 = hmm & n = 2\n");
	printf("Returned Value: %s\n", ft_strncat(box5, box6, 2));
	printf("string: %s\n", box5);
	printf("-------------\n");
	printf("ft_strlcat test:\n");
	char box7[10] = "lmao";
	char box8[10] = "hmm";
	printf("string1 = lmao & string2 = hmm & size = 7\n");
	printf("Returned Value: %d\n", (int)ft_strlcat(box7, box8, 7));
	printf("string: %s\n", box7);
	printf("-------------\n");
	printf("strchr test:\n");
	printf("string: mouse & int: o\n");
	printf("Returned Value: %s\n", (char*)strchr("mouse", 'o'));
	printf("-------------\n");
	printf("ft_strchr test:\n");
	printf("string: mouse & int: o\n");
	printf("Returned Value: %s\n", (char*)ft_strchr("mouse", 'o'));
	printf("-------------\n");
	printf("strrchr test:\n");
	printf("string: member & int: m\n");
	printf("Returned Value: %s\n", (char*)strrchr("member", 'm'));
	printf("-------------\n");
	printf("ft_strrchr test:\n");
	printf("string: member & int: m\n");
	printf("Returned Value: %s\n", (char*)ft_strrchr("member", 'm'));
	printf("-------------\n");
	printf("strstr test:\n");
	printf("string1: execute & string2: cu\n");
	printf("Returned Value: %s\n", strstr("execute", "cu"));
	printf("-------------\n");
	printf("ft_strstr test:\n");
	printf("string1: execute & string2: cu\n");
	printf("Returned Value: %s\n", ft_strstr("execute", "cu"));
	printf("-------------\n");
	printf("ft_strnstr test:\n");
	printf("string1: execute & string2: cut\n");
	printf("Returned Value: %s\n", ft_strnstr("execute", "cut", 2));
	printf("-------------\n");
	printf("strcmp test:\n");
	printf("string1: execute & string2: cut\n");
	printf("Returned Value: %d\n", strcmp("execute", "cut"));
	printf("-------------\n");
	printf("ft_strcmp test:\n");
	printf("string1: execute & string2: cut\n");
	printf("Returned Value: %d\n", ft_strcmp("execute", "cut"));
	printf("-------------\n");
	printf("strncmp test:\n");
	printf("string1: execute & string2: cut & n = 2\n");
	printf("Returned Value: %d\n", strncmp("execute", "cut", 2));
	printf("-------------\n");
	printf("ft_strncmp test:\n");
	printf("string1: execute & string2: cut & n = 2\n");
	printf("Returned Value: %d\n", ft_strncmp("execute", "cut", 2));
	printf("-------------\n");
	printf("atoi test:\n");
	printf("string: \"[23s\"\n");
	printf("Returned Value: %d\n", atoi("[23s"));
	printf("-------------\n");
	printf("ft_atoi test:\n");
	printf("string: \"234s\"\n");
	printf("Returned Value: %d\n", ft_atoi("234s"));
	printf("-------------\n");
	printf("ft_isalpha test:\n");
	printf("input: c\n");
	printf("Returned Value: %d\n", ft_isalpha('c'));
	printf("-------------\n");
	printf("ft_isdigit test:\n");
	printf("input: c\n");
	printf("Returned Value: %d\n", ft_isdigit('c'));
	printf("-------------\n");
	printf("ft_isalnum test:\n");
	printf("input: c\n");
	printf("Returned Value: %d\n", ft_isalnum('c'));
	printf("-------------\n");
	printf("ft_isascii test:\n");
	printf("input: 128\n");
	printf("Returned Value: %d\n", ft_isascii(128));
	printf("-------------\n");
	printf("ft_isprint test:\n");
	printf("input: 32\n");
	printf("Returned Value: %d\n", ft_isprint(32));
	printf("-------------\n");
	printf("ft_toupper test:\n");
	printf("input: a\n");
	printf("Returned Value: %c\n", ft_toupper('a'));
	printf("-------------\n");
	printf("ft_tolower test:\n");
	printf("input: 'A'\n");
	printf("Returned Value: %c\n", ft_tolower('A'));
	return (0);
}
