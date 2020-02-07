/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:29:02 by fcatusse          #+#    #+#             */
/*   Updated: 2020/02/07 00:18:28 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	**ft_tabcopy(char **tab_dest, char **tab_copy)
{
	int		i;

	i = -1;
	if (!(tab_dest = malloc(sizeof(char *) * (ft_tablen(tab_copy) + 1))))
		return (NULL);
	while (tab_copy && tab_copy[++i])
		if (!(tab_dest[i] = ft_strdup(tab_copy[i])))
		{
			ft_tabfree(tab_dest);
			return (NULL);
		}
	tab_dest[i] = 0;
	return (tab_dest);
}
