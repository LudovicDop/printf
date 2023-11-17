/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:32:03 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/17 15:26:37 by ldoppler         ###   ########.fr       */
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

void	search_good_fc(char carac, va_list args, t_info *info)
{
	if (carac == 'c')
		ft_c(args, info);
	else if (carac == 's')
		ft_string(args, info);
	else if (carac == 'p')
		ft_p(args, info);
	else if (carac == 'd')
		ft_int(args, info);
	else if (carac == 'i')
		ft_int(args, info);
	else if (carac == 'u')
		ft_u(args, info);
	else if (carac == 'x')
		ft_x(args, info);
	else if (carac == 'X')
		ft_x2(args, info);
	else if (carac == '%')
		printf("Sign\n");
	else
		printf("error\n");
}

int	ft_printf(const char *string, ...)
{
	int		i;
	va_list	args;	
	t_info	info;

	va_start(args, string);
	info.count = 0;
	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] != '%')
		{
			ft_putchar_fd(string[i], 1);
		}
		if (modulo_sum(string[i]))
		{
			search_good_fc(string[++i], args, &info);
			info.count--;
		}
		info.count++;
		i++;
	}
	va_end(args);
	return (info.count);
}
