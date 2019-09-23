/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:15:49 by fcatusse          #+#    #+#             */
/*   Updated: 2019/09/23 13:52:58 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

int		ft_tablen(char **array)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (array[++i])
		count++;
	return (count);
}
