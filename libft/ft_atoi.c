#include <libft.h>

static	check(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' ||
		s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char* s)
{
	int i;
	int ans;
	int c;
	int j;
	int positive;
	c = 0;
	j = 1;
	i = 0;
	ans = 0;
	positive = 1;
	i = check((char*)s, i);
	s[i] == '+' ? i++ : continue;
	else if (s[i] == '-'){
		positive = 0;
		i++;
	}
	while (s[i] != '\0'){
		if (s[i] >= 48 && s[i] <= 57){
			j = s[i] - '0';
			ans = (ans * 10) + j;
		}
		else
			break;
		c++;
		i++;
	}
	if (c > 10 && !positive && (ans > 100000000 || ans < -100000000))
		return (0);
	else if (c > 10 && positive && (ans > 100000000 || ans < -100000000))
		return (-1);
	if (!positive)
		return (ans * (-1));
	else
		return (ans);
}
