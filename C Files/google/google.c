
int functionPow(int target)
{
	int x = 2;
	int y = 2;
	
		while (1)
		{
			while (1)
			{
				if (target == pow(x, y))
					return 1;
				if (pow(x, y) > target)
					break ;
				y++;
			}
			x++;
			y = 2;
			if (x >= target)
				break ;
		}
		return 0;
}

int dick(int target)
{
	int counter = 2;
	int x =
	while (target < 50001)
	{
		target = pow(target, counter);
		if (target > 5000 && target < 50001)
			
	}
}

int main(void)
{
	 int y = 2;
	 int x = 2;
	// while (i < 5000)
	// {
	// 	if ((i % 3 == 0) || (i % 7 == 0) || (i % 11 == 0))
	// 		x++;
	// 	i++;
	// }
	// printf("x: %d\n", x);
	int target = 5000;
	x = 0;
	while (target < 50001)
	{
		x += functionPow(target);
		target++;
	}
	printf("target: %d\n", target);
}