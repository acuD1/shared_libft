/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:28:46 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/07 14:30:00 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void	*ft_memset(void *s, int32_t c, size_t len)
{
	unsigned char	*tmp;

	tmp = s;
	while (len--)
		*tmp++ = (unsigned char)c;
	return (s);
}
