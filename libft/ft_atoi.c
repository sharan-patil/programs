#include <libft.h>

int	ft_atoi(const char* s)
{
	int i, n, j, positive = 1, c, ans;
	c = 0;
	j = 1;
	i = 0;
	n = 0;
	ans = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		positive = 0;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			j = s[i] - '0';
			ans = (ans * 10) + j;
		}
		else
			break ;
		c++;
		i++;
	}
	if (c > 10 && !positive)
		return (0);
	else if (c > 10 && positive)
		return (-1);
	if (!positive)
		return (ans * (-1));
	else
		return (ans);
}
