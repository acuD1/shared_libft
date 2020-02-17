/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <fcatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:22:52 by fcatusse          #+#    #+#             */
/*   Updated: 2020/02/17 13:25:40 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

int8_t		ft_str_isprint(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!ft_is_print(str[i]))
			return (0);
	}
	return (1);
}
