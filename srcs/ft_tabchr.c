/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 00:50:59 by mpivet-p          #+#    #+#             */
/*   Updated: 2020/02/06 18:51:50 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	**ft_tabchr(char **tab_src, char *str)
{
	int i;

	i = 0;
	if (tab_src && str)
	{
		while (tab_src[i])
		{
			if (ft_strcmp(tab_src[i], str) == 0)
				return (tab_src + i);
			i++;
		}
	}
	return (NULL);
}
