/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:27:26 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/07 14:27:35 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void	*ft_memcpy(void *dst, const void *s, size_t n)
{
	size_t		i;
	char		*tmp_dst;
	const char	*tmp_s;

	i = 0;
	tmp_dst = dst;
	tmp_s = s;
	while (n--)
	{
		tmp_dst[i] = tmp_s[i];
		i++;
	}
	return (dst);
}
