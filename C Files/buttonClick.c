#include <stdio.h>

int	GetDigitalInput(void)
{
	int a;
	scanf("%d", &a);
	return a;
}

void	main(void)
{
	int x = 127;
	char prev = 'h';
	char now = 'h';
	while (1)
	{
		printf("setMotor(1, %d);", x);
		prev = now;
		now = 'h';
		if (GetDigitalInput() == 0)
		{
			now = 'f';
		}
		if (prev == 'h' && now == 'f')
			x = x * -1;
	}
}
