int     ft_max(int *tab, int length)
{
    int x;
    int y;
    int z;

    z = 0;
    y = 0;
    x = 1;
    while (z < length)
    {
        if(tab[x] >= tab[x - 1])
            y = tab[x];
        else
            y = tab[x - 1];
        x++;
        z++;
    }
    return (y);
}

int main(void)
{
    int *b = {1,2,3,4};
    int a = ft_max(*b,4);
    return (a);
}
