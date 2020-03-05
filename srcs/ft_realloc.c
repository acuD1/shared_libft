/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:05:02 by fcatusse          #+#    #+#             */
/*   Updated: 2020/03/05 01:08:24 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	*ft_realloc(char *ptr, size_t size)
{
	char	*new;

	new = NULL;
	if (!(new = ft_strnew(size)))
		return (NULL);
	ft_strcpy(new, ptr);
	ft_strdel(&ptr);
	return (new);
}
