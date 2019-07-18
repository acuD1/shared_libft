/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:30:36 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/09 10:33:35 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shared_libft.h"

size_t	ft_strclen(const char *s, int32_t c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}
