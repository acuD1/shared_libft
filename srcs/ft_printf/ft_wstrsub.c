/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:05:16 by arsciand          #+#    #+#             */
/*   Updated: 2020/03/04 23:52:47 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len)
{
	size_t	real_len;
	size_t	i;
	char	*fresh;

	real_len = 0;
	i = 0;
	while (ws[i] != '\0' && len >= ft_wcharlen(ws[i]))
	{
		len -= ft_wcharlen(ws[i]);
		real_len += ft_wcharlen(ws[i]);
		i++;
	}
	fresh = ft_transform_wchar_in_char(ws);
	return (ft_strsub_free(fresh, start, real_len));
}
