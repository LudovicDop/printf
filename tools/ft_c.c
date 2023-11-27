/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:06:11 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/23 13:58:42 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_c(va_list args, t_info *info)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	info->count++;
}
