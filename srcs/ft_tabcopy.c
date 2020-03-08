/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:29:02 by fcatusse          #+#    #+#             */
/*   Updated: 2020/03/08 13:59:30 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"
#include <stdlib.h>

char	**ft_tabcopy(char **tab_dest, char **tab_copy)
{
	size_t	i;

	i = 0;
	if (!(tab_dest = (char**)malloc(sizeof(char*) * (ft_tablen(tab_copy) + 1))))
		return (NULL);
	while (tab_copy && tab_copy[i])
	{
		if (!(tab_dest[i] = ft_strdup(tab_copy[i])))
		{
			ft_tabfree(tab_dest);
			return (NULL);
		}
		i++;
	}
	tab_dest[i] = 0;
	return (tab_dest);
}
