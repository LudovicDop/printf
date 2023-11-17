#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char *test = "Hello World!";
		
	int x = printf("=> %p", test);
	printf("value1 %d\n",x);
	int y = ft_printf("=> %p", test);
	printf("value %d\n",y);
	return (0);
}
