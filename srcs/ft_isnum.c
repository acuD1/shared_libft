/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:35:57 by fcatusse          #+#    #+#             */
/*   Updated: 2020/02/07 00:15:37 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

u_int8_t		ft_isnum(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		++str;
	}
	return (1);
}
