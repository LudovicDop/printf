/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:39:03 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/23 14:15:03 by ldoppler         ###   ########.fr       */
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
	ret = malloc(sizeof(char) * 21);
	if (!ret)
		return (NULL);
	while (i < (int)ft_strlen(val))
	{
		buffer = ft_tolower(val[j]);
		ret[i] = buffer;
		j--;
		i++;
	}
	ret[i] = '\0';
	free(val);
	return (ret);
}

static char	*search_hexa(unsigned long p_val)
{
	unsigned long	reminder;
	int				i;
	char			*ret;

	ret = malloc(sizeof(char) * 21);
	if (!ret)
		return (NULL);
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
	ret[i] = 'x';
	ret[++i] = '0';
	ret[++i] = '\0';
	return (reverse(ret));
}

void	ft_p(va_list args, t_info *info)
{
	void			*p;
	unsigned long	p_val;
	char			*ret;

	p = va_arg(args, void *);
	p_val = (unsigned long)p;
	if (p_val == 0)
	{
		ft_putstr_fd("0x0", 1);
		info->count += 3;
		return ;
	}
	ret = search_hexa(p_val);
	if (!ret)
		return ;
	info->count += ft_strlen(ret);
	ft_putstr_fd(ret, 1);
	if (ret)
		free(ret);
	return ;
}
