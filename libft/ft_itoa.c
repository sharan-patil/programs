#include <libft.h>

char	*ft_itoa(int n)
{
	char *new;
	int temp, i, j, len, positive = 1;
	new = (char*)malloc(15);
	j = 0;
	temp = n;
	i = 0;
	if (n < 0)
	{
		positive = 0;
		new[0] = '-';
		n *= -1;
	}
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	len = i;
	temp = 1;
	while (j < i - 1)
	{
		temp *= 10;
		j++;
	}
	i = 0;
	if (positive == 0)
	{
		i++;
		len++;
	}
	while (i < len)
	{
		new[i] = n / temp + 48;
		n %= temp;
		temp /= 10;
		i++;
	}
	return (&new[0]);
}
