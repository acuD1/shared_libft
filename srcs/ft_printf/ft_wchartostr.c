/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:13:42 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/04 23:48:50 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_wchartostr_bis(char *s, wchar_t wc)
{
	if (wc < 0x800)
	{
		*(s++) = ((wc >> 6) & 0x1F) | (char)0xC0;
		*(s++) = ((wc >> 0) & 0x3F) | (char)0x80;
		return (2);
	}
	else if (wc < 0x10000)
	{
		*(s++) = ((wc >> 12) & 0xF) | (char)0xE0;
		*(s++) = ((wc >> 6) & 0x3F) | (char)0x80;
		*(s++) = ((wc >> 0) & 0x3F) | (char)0x80;
		return (3);
	}
	else if (wc < 0x110000)
	{
		*(s++) = ((wc >> 18) & 0x7) | (char)0xF0;
		*(s++) = ((wc >> 12) & 0x3F) | (char)0x80;
		*(s++) = ((wc >> 6) & 0x3F) | (char)0x80;
		*(s++) = ((wc >> 0) & 0x3F) | (char)0x80;
		return (4);
	}
	return (0);
}

int				ft_wchartostr(char *s, wchar_t wc)
{
	if (wc < 0x80)
	{
		*s = ((wc & 0x7F) | 0);
		return (1);
	}
	return (ft_wchartostr_bis(s, wc));
}
