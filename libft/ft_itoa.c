#include <libft.h>

char	*ft_itoa(int n)
{
	char *new;
	long int temp, i, j, len, positive = 1, tn;
	tn = (long int) n;
	j = 0;
	temp = tn;
	i = 0;
	if (tn < 0)
	{
		positive = 0;
		tn *= -1;
	}
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	len = i;
	if (n == 0)
		len++;
	new = (char*)malloc(len + 1 + !positive);
	if (!new)
		return (NULL);
	if (i == 0)
	{
		new[0] = '0';
		new[1] = '\0';
		return (&new[0]);
	}
	if (!positive)
		new[0] = '-';
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
	new[i] = '\0';
	return (&new[0]);
}
