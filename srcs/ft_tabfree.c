/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:26:20 by fcatusse          #+#    #+#             */
/*   Updated: 2019/07/19 11:46:10 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "shared_libft.h"

void		ft_tabfree(char **array)
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
