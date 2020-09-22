int main(void)
{
	int i = 1;
	int counter = 0;
	while (i < 1001)
	{
		if (i % 15 == 0)
			counter += i * 10;
		else if (i % 3 == 0)
			counter += i * 2;
		else if (i % 5 == 0)
			counter += i * 3;
		else
			counter += i;
		i++;
	}
	printf("counter: %d\n", counter);
}