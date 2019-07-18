/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:48:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/07 13:48:35 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void		ft_tabdel(char ***tab)
{
	char	**tmp;
	size_t	i;

	if (!*tab)
		return ;
	tmp = *tab;
	i = 0;
	if (*tab)
	{
		while (tmp[i])
			free(tmp[i++]);
		free(*tab);
	}
	*tab = NULL;
}
