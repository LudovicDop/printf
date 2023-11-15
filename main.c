#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	unsigned int x = 2147483650;
	printf("%cHellx World %d %i %u\n",'a', 42,42,x);
	ft_printf("%cHello World %d %s %u\n",'a', 42,"Batard de merde",x);
	return (0);
}
