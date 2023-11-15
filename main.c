#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int x = printf(" %s ","Hello");
	printf("value1 %d\n",x);
	int y = ft_printf(" %s ","Hello");
	printf("value %d\n",y);
	return (0);
}
