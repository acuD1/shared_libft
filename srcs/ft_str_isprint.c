/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:22:52 by fcatusse          #+#    #+#             */
/*   Updated: 2020/03/05 01:08:48 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

u_int8_t	ft_str_isprint(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_print(str[i]))
			return (0);
		i++;
	}
	return (1);
}
