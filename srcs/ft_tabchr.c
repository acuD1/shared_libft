/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 00:50:59 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/09/30 00:59:33 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	**ft_tabchr(char **tab, char *str)
{
	int i;

	i = 0;
	if (tab && str)
	{
		while (tab[i])
		{
			if (ft_strcmp(tab[i], str) == 0)
				return (tab + i);
			i++;
		}
	}
	return (NULL);
}
