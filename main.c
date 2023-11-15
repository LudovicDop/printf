#include "ft_printf.h"

int	sum(int count, ...)
{
	va_list	args;
	va_start(args, count);
	
	int	s;
	int	x;
	
	x = va_arg(args, int);	
	s = 0;
	while (x)
	{
		s += x;
		x = va_arg(args, int);
	}
	va_end(args);
	return(s);
}

int	main(void)
{
	printf("Hello World!\n");
	printf("Sum = %d\n",sum(3, 1, 2, 3, NULL));
	ft_printf("Hello World");
	return (0);
}
