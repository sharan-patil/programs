#include <stdio.h>

int reverseNum(int n)
{
	int revNum = 0;
	
	revNum = (n % 10) * 100;
	revNum += ((n / 10) % 10) * 10;
	revNum += (n / 100);
	return revNum;
}

int main(void)
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	a = reverseNum(a);
	b = reverseNum(b);
	if (a > b)
		printf("%d", a);
	else
		printf("%d", b);
	return 0;
}
