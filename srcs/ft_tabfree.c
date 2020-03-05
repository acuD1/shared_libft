/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:26:20 by fcatusse          #+#    #+#             */
/*   Updated: 2020/03/05 01:15:53 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void	ft_tabfree(char **array)
{
	size_t	i;

	i = 0;
	if (array)
	{
		while (array[i])
			ft_strdel(&array[i++]);
		free(array);
		array = NULL;
	}
}
