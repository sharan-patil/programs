#include <stdio.h>

int main(void)
{
	int i = 1;
	int n, rating;
	
	scanf("%d %d", &n, &rating);
	rating -= 1;
	while (1)
	{
		if (i / n == rating)
		{
			printf("%d", i + 1);
			break ;
		}
		i++;
	}
	return 0;
}
