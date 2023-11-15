/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:06:11 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/15 13:22:31 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_c(const char *string, va_list args)
{
	int		i;
	char	c;
	
	i = 0;
	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
}
