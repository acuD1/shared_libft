/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:34:49 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/09 10:35:04 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

int32_t	ft_strcmp(const char *s1, const char *s2)
{
	return (*s1 && *s2 && *s1 == *s2
			? ft_strcmp(++s1, ++s2) : (unsigned char)*s1 - (unsigned char)*s2);
}
