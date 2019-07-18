/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:29:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/09 10:33:26 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	*ft_strchr(const char *s, int32_t c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char*)s);
		s++;
	}
	return (!(char)c ? (char *)&s[ft_strlen(s)] : NULL);
}
