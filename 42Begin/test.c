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
	printf("-------------\n");
	char lul[10] = "lmao";
	char lul2[10] = "abcd";
	char *hmm;
	hmm = memcpy(lul, lul2, 2);
	printf("%s\n", hmm);
	char lmao[5] = "1";
	if (lmao[0] == 49)
		printf("\nWTF\n");
}