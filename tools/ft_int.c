/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:26:48 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/17 13:18:54 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int	calc_int_lenght(int val)
{
	int				lenght;
	unsigned int	val2;

	val2 = val;
	lenght = 0;
	if (val < 0)
	{
		val2 = val * -1;
		lenght++;
	}
	if (val == 0)
		return (1);
	while (val2 != 0)
	{
		lenght++;
		val2 /= 10;
	}
	return (lenght);
}

void	ft_int(va_list args, t_info *info)
{
	int	x;

	x = va_arg(args, int);
	info->count += calc_int_lenght(x);
	ft_putnbr_fd(x, 1);
}
