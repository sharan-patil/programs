#include <stdio.h>

void    ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
        ******c = **a;
}

int main(void)
{
    int a = 1, b = 2, c = 3, d = 4;
    ft_scrambler(*a,b,c,d);
    printf("%d", a);
    return (0);
}
