#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	test = -10;
	
	int x = printf("Real => %x\n", test);
	printf("Real value1 %d\n",x);
	int y = ft_printf("Fake => %x\n", test);
	printf("Fake value %d\n",y);
	return (0);
}
