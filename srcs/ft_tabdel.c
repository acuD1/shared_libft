/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:48:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/19 12:00:38 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void		ft_tabdel(char ***array)
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
			free(tmp[i++]);
		free(*array);
	}
	*array = NULL;
}
