//#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

int ft_printf(const char* format, ...);

int main(void)
{
	printf("{%010.0jd}\n", (intmax_t) 0);
	ft_printf("{%10.0jd}\n", (intmax_t) 0);
	return 0;
}
