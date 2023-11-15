#include "ft_printf.h"

int	main(void)
{
	printf("%cHellx World %d\n",'a', 42);
	ft_printf("%cHello World %d %s\n",'a', 42,"Batard de merde");
	return (0);
}
