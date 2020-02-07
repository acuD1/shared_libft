/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:26:20 by fcatusse          #+#    #+#             */
/*   Updated: 2020/02/07 00:18:37 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void	ft_tabfree(char **array)
{
	int		i;

	i = -1;
	if (array)
	{
		while (array[++i])
			ft_strdel(&array[i]);
		free(array);
		array = NULL;
	}
}
