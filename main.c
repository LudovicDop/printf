#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	test = -42;
	
	int x = printf("Real => %u\n", test);
	printf("Real value1 %d\n",x);
	int y = ft_printf("Fake => %u\n", test);
	printf("Fake value %d\n",y);
	return (0);
}
