int	main(void)
{
	char str1[50] = "Thinking...";
	char str2[50] = "Overly desperate...";
	printf("Memcpy: \n");
	printf("Before: %s\n", str1);
	memcpy(str1, str2, 3);
	printf("After: %s\n", str1);
	char str3[50] = "Thinking...";
	char str4[50] = "Overly desperate...";
	printf("Before: %s\n", str3);
	memmove(str3, str4, 3);
	printf("After: %s\n", str3);	
}