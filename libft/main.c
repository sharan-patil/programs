#include <libft.h>

int main(void)
{
    char arr[] = "MZIRIBMZIRIBMZE123";
    char arr2[] = "MZIRIBMZE";
    printf("%s\n", ft_strnstr(arr, arr2, ft_strlen(arr2)));
    printf("%s\n", strnstr(arr, arr2, ft_strlen(arr2)));
    return (0);
}
