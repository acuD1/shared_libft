/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:13:31 by guvillat          #+#    #+#             */
/*   Updated: 2019/01/23 15:13:32 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}

size_t		ft_wbytelen(wchar_t *ws)
{
	size_t	len;
	size_t	bytelen;

	len = ft_wstrlen(ws);
	bytelen = 0;
	while (len > 0)
	{
		bytelen += ft_wcharlen(*ws);
		ws++;
		len--;
	}
	return (bytelen);
}
