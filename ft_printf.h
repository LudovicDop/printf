/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:29:17 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/17 13:10:55 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_info
{
	int	count;
}	t_info;
int		ft_printf(const char *string, ...);
void	ft_c(va_list args, t_info *info);
void	ft_int(va_list args, t_info *info);
void	ft_string(va_list args, t_info *info);
void	ft_u(va_list args);
void	ft_p(va_list args, t_info *info);
