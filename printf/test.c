#include <string.h>
#include <stdio.h>

int checkFour(int q)
{
	int n;
	while (q != 0)
	{
		n = q % 10;
		q = q / 10;
		if (n == 4)
			return 0;
	}
    return 1;
}

int main(void)
{
	int n, i, j, p, flag;
	
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
		flag = 0;
        scanf("%d", &p);
        for (j = p / 2; j < p; j++)
        {
            if (checkFour(j) && checkFour(p - j))
            {
                printf("Case #%d: %d %d", i, j, p - j);
				flag = 1;
                break ;
            }
        }
		if (!flag)
		{
			for (j = 1; j < p / 2; j++)
			{
				if (checkFour(j) && checkFour(p - j))
	            {
	                printf("Case #%d: %d %d", i, j, p - j);
	                break ;
	            }
			}
		}
    }
}