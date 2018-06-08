#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *des, *sour;
	size_t i;
	i = -1;
    sour = (char*)src;
	des = dest;
    if (sour < des)
    {
        i = n - 1;
        while ((int)i >= 0)
        {
            des[i] = sour[i];
            i--;
        }
    }
    else
    {
        while (++i < n)
            des[i] = sour[i];
    }
    return (dest);
}
