#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	long	test = LONG_MIN;
	
	int x = printf("Real => %u\n", (unsigned int)test);
	printf("Real value1 %d\n",x);
	int y = ft_printf("Fake => %u\n", test);
	printf("Fake value %d\n",y);
	return (0);
}
