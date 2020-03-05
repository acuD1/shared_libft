/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:21:03 by mpivet-p          #+#    #+#             */
/*   Updated: 2020/03/05 01:05:52 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

int8_t	ft_itoabuf(int32_t number, char *buffer)
{
	char	*str;

	str = NULL;
	if (buffer == NULL || (str = ft_itoa(number)) == NULL)
		return (-1);
	ft_strcat(buffer, str);
	ft_strdel(&str);
	return (0);
}
