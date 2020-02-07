/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:18:53 by fcatusse          #+#    #+#             */
/*   Updated: 2020/02/07 05:00:22 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

int			ft_isstart(const char *s1, const char *s2)
{
	int		i;

	i = -1;
	if (!*s2 || !*s1)
		return (0);
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
