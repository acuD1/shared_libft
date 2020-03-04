/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:15:49 by fcatusse          #+#    #+#             */
/*   Updated: 2020/03/04 23:17:08 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

size_t	ft_tablen(char **array)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (array[i])
	{
		count++;
		i++;
	}
	return (count);
}
