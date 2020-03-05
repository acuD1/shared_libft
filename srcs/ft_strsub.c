/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:51:25 by arsciand          #+#    #+#             */
/*   Updated: 2020/03/05 01:24:26 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dst = ft_memalloc(len + 1)))
		return (NULL);
	while (i < len)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
