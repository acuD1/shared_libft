/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:42:24 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/05 01:13:38 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char*)big);
	i = 0;
	j = 0;
	while (big[i])
	{
		while (little[j] && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char*)(big + i));
		j = 0;
		i++;
	}
	return (NULL);
}
