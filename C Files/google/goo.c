#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func(int target)
{
	char* string = malloc(100);
	itoa(target, string, 10);
	int i = 0;
	int len = strlen(string);
	while (i < len - 1)
	{
		if (string[i] >= string[i + 1])
			return 0;
		i++;
	}
	return 1;
}

int main(void)
{
	int a = 1;
	int b = 1;
	int counter = 0;
	while (a < 1001)
	{
		b = a;
		while (b < 1001)
		{
			if (a * b > 1000)
				break ;
			if (func(a * b))
			{
				counter++;
				printf("a: %d b: %d p: %d\n", a, b, a*b);
			}
			b++;
		}
		b = 1;
		a++;
	}
	printf("counter: %d\n", counter);
	return 0;
}