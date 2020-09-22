#include <stdio.h>
#include <limits.h>
#include <sys/types.h>
#include <inttypes.h>

int ft_printf(const char* format, ...);

int main(void)
{
	ssize_t a;
	a = -2;
	void *ptr;
	ft_printf("%jd - %d\n", (intmax_t)12, sizeof(intmax_t));
	return 0;
}
