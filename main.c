#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int x = printf("%s","Hello World!");
	printf("%d",x);
	ft_printf("%c",'0' - 256);
	return (0);
}
