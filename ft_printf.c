/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:32:03 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/15 13:23:56 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	modulo_sum(char carac)
{
	if (!carac)
		return (0);
	if (carac == '%')
	{
		return (1);
	}
	return (0);
}

void	search_good_fc(const char *string, char carac, va_list args)
{
	if (carac == 'c')
	{
		ft_c(string, args);
		//printf("Char\n");
	}
	else if (carac == 's')
		printf("String\n");
	else if (carac == 'p')
		printf("Pointer in hexa\n");
	else if (carac == 'd')
		printf("INT\n");
	else if (carac == 'i')
		printf("Integer base 10\n");
	else if (carac == 'u')
		printf("Unsigned decimal base 10\n");
	else if (carac == 'x')
		printf("Hexa base 16 lowercase");
	else if (carac == 'X')
		printf("Hexa uppercase\n");
	else if (carac == '%')
		printf("Sign\n");
	else
		printf("error\n");	
}
int	*ft_printf(const char *string, ...)
{
	int		i;
	va_list	args;	
	va_start(args, string);
	i = 0;
	if (!string)
		return (NULL);
	while (string[i])
	{
		if (string[i] != '%')
			ft_putchar_fd(string[i], 1);
		if (modulo_sum(string[i]))
		{
			search_good_fc(string, string[++i], args);
		}
		i++;
	}
	va_end(args);
	return (0);
}
