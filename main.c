#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char *test = NULL; 
		
	int x = printf("Real => %p", test);
	printf("Real value1 %d\n",x);
	int y = ft_printf("Fake => %p", test);
	printf("Fake value %d\n",y);
	return (0);
}
