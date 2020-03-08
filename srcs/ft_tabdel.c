/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:48:03 by arsciand          #+#    #+#             */
/*   Updated: 2020/03/08 14:00:31 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"
#include <stdlib.h>

void	ft_tabdel(char ***array)
{
	char	**tmp;
	size_t	i;

	if (!*array)
		return ;
	tmp = *array;
	i = 0;
	if (*array)
	{
		while (tmp[i])
			ft_strdel(&(tmp[i++]));
		free(*array);
	}
	*array = NULL;
}
