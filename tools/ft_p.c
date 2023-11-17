/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:39:03 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/16 17:46:59 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long	calc_int_lenght(unsigned long val)
{
	int lenght;
	
	lenght = 0;
	if (val == 0)
		return (1);
	while (val != 0)
	{
		lenght++;
		val /= 10;
	}
	printf("lenght = %d\n",lenght);
	return (lenght);
}
char	*search_hexa(unsigned long p_val)
{
	unsigned long reminder;
	int		i;
	char	*ret = malloc(sizeof(char) * calc_int_lenght(p_val));
	
	i = 0;
	reminder = p_val;	
	while (p_val != 0)
	{
		reminder = p_val % 16;
		if (reminder < 10)
			ret[i] = reminder % 16 + '0';
		else 
			ret[i] = reminder - 10 + 'A';
		printf("ICI %c\n",ret[i]);
		p_val /= 16;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
void	ft_p(va_list args, t_info *info)
{
	void *p = va_arg(args, void*);
	unsigned long p_val = (unsigned long)p;
	printf("%zu",p_val);
	search_hexa(p_val);
	return ;	
}
