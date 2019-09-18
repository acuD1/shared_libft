/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:21:03 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/09/18 17:38:29 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

int8_t	ft_itoabuf(int number, char *buffer)
{
	char	*str;

	str = NULL;
	if (buffer == NULL || (str = ft_itoa(number)) == NULL)
		return (-1);
	ft_strcat(buffer, str);
	ft_strdel(&str);
	return (0);
}
