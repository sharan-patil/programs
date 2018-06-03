#include <libft.h>

int	ft_atoi(const char* s)
{
	int i, n, j, positive, c, ans;
	c = 0;
	j = 1;
	i = 0;
	n = 0;
	ans = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
	{
		i++;
	}		
	if (s[i] == '-')
	{
		positive = 0;
		i++;
	}
	if (s[i] == '+')
	{
		positive = 1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		n = (j * (s[i] - 48)) + n;
		j *= 10;
		i++;
		c++;
	}
	j /= 10;
	while (n != 0)
	{
		ans = ((n % 10) * j) + ans;
		j /= 10;
		n = n / 10;
	}
	if (positive == 0)
		ans *= -1;
	return (ans);
}
