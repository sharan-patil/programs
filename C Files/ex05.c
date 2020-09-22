int     ft_button(int i, int j, int k)
{
    if ((i < j && k > j) || (k < j && i > j))
        return (j);
    else if ((j < i && k > i) || (k < i && j > i))
            return (i);
    else if ((i < k && j > k) || (j < k && i > k))
        return (k);
    else if (i == j)
        return (i);
    else if (j == k)
        return (k);
    else
        return (i);
}

int main(void)
{
    return (ft_button(1,5,4));
}
