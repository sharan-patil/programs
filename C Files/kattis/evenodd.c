#include <stdio.h>

int main(void)
{
	int n;
	int i = 0;
	int p;
	
	scanf("%d", &n);
	while (i < n)
	{
		scanf("%d", &p);
		if (p % 2 == 0)
			printf("%d is even\n", p);
		else
			printf("%d is odd\n", p);
		i++;
	}
	return 0;
}
