#include <stdio.h>
#include <fcntl.h>

int g_testCases;
int damage[100];
char *sequences[100];

int	main(void)
{
	int i;
	
	i = 0;
	scanf("%d", &g_testCases);
	while (i < g_testCases)
	{
		scanf("%d", &damage[i]);
		scanf("%s", sequences[i]);
		i++;
	}
	return 0;
}