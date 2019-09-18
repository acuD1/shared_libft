/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:46:04 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/09 10:47:43 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

u_int8_t		ft_strequ(const char *s1, const char *s2)
{
	return (s1 && s2 && ft_strcmp(s1, s2) == 0 ? 1 : 0);
}