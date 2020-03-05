/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:23:18 by fcatusse          #+#    #+#             */
/*   Updated: 2020/03/05 00:58:05 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

size_t	ft_decade(int32_t nbr)
{
	size_t	size;

	size = 0;
	while (nbr != 0)
	{
		size++;
		nbr = nbr / 10;
	}
	return (size);
}
