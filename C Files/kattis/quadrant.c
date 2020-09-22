int main(void)
{
    double x, y;
    
    scanf("%le %le", &x, &y);
    if (x > 0)
	{
        if (y > 0)
            printf("1");
        if (y < 0)
            printf("4");
    }
	if (x < 0)
    {
	    if (y > 0)
            printf("2");
        if (y < 0)
            printf("3");
    }
	return 0;
}
