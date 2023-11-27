/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:37:08 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/23 14:19:23 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_string(va_list args, t_info *info)
{
	char	*string;

	string = ft_strdup(va_arg(args, char *));
	if (!string)
	{
		string = ft_strdup("(null)");
		if (!string)
			return ;
		ft_putstr_fd(string, 1);
		info->count += ft_strlen(string);
		free(string);
		return ;
	}
	ft_putstr_fd(string, 1);
	if (*string != '\0')
		info->count += ft_strlen(string);
	if (string)
		free(string);
}
