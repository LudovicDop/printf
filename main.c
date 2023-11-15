#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int x = printf("%c %c %c",'A','B','C');
	printf("value %d\n",x);
	int y = ft_printf("%c %c %c",'A', 'B', 'C');
	printf("value %d\n",y);
	return (0);
}
