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
