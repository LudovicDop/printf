/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:24:23 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/17 15:27:12 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*reverse(char *val)
{
	char	*ret;
	char	buffer;
	int		i;
	int		j;

	j = ft_strlen(val) - 1;
	i = 0;
	ret = malloc(sizeof(char) * ft_strlen(val) + 1);
	while (i < (int)ft_strlen(val))
	{
		buffer = ft_toupper(val[j]);
		ret[i] = buffer;
		j--;
		i++;
	}
	ret[i] = '\0';
	free(val);
	return (ret);
}

static unsigned int	calc_int_lenght(unsigned int val)
{
	int	lenght;

	lenght = 0;
	if ((int)val < 0)
		lenght--;
	if (val == 0)
		return (1);
	while (val != 0)
	{
		val /= 10;
		lenght++;
	}
	return (lenght);
}

static int search_malloc(unsigned int p_val)
{
	unsigned int	reminder;
	int				i;

	i = 0;
	reminder = p_val;
	while (p_val != 0)
	{
		reminder = p_val % 16;
		p_val /= 16;
		i++;
	}
	return (i);
}

static char	*search_hexa(unsigned int p_val)
{
	unsigned int	reminder;
	int				i;
	char			*ret;

	ret = malloc(sizeof(char) * search_malloc(p_val) + 1);
	i = 0;
	reminder = p_val;
	while (p_val != 0)
	{
		reminder = p_val % 16;
		if (reminder < 10)
			ret[i] = reminder % 16 + '0';
		else
			ret[i] = reminder - 10 + 'A';
		p_val /= 16;
		i++;
	}
	ret[i] = '\0';
	return (reverse(ret));
}

void	ft_x2(va_list args, t_info *info)
{
	unsigned int	val;
	char			*ret;

	val = va_arg(args, unsigned int);
	if (val == 0)
	{
		write(1, "0", 1);
		info->count++;
		return ;
	}
	ret = search_hexa(val);
	info->count += ft_strlen(ret);
	ft_putstr_fd(ret, 1);
	free(ret);
}
