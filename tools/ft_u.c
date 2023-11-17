/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:11:17 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/17 13:45:10 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void read_unsigned(unsigned long n, int fd, t_info *info)
{
	unsigned int	unsigned_n;
	char			buffer;

	buffer = '\0';
	unsigned_n = n;
	if (unsigned_n > 0)
	{
		buffer = unsigned_n % 10 + '0';
		read_unsigned((unsigned_n / 10), fd, info);
	}
	if (buffer)
	{
		write(fd, &buffer, 1);
		info->count++;
	}
}

void	ft_u(va_list args, t_info *info)
{
	unsigned int	val;
	
	val = va_arg(args, unsigned int);
	read_unsigned(val, 1,info);
	if (val == 0)
	{
		write(1, "0", 1);
		info->count++;
	}
}
