#include <libft.h>

char	*ft_itoa(int n)
{
	char *new;
	long int temp, i, j, len, positive = 1, tn;
	tn = (long int) n;
	new = (char*)malloc(15);
	j = 0;
	temp = tn;
	i = 0;
	if (tn < 0)
	{
		positive = 0;
		new[0] = '-';
		tn *= -1;
	}
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	if (i == 0)
		return ("0");
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
		new[i] = tn / temp + 48;
		tn %= temp;
		temp /= 10;
		i++;
	}
	return (&new[0]);
}
