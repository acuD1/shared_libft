/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:14:04 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/04 23:59:30 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putwchar_in_char(wchar_t wchar, char *fresh, int i)
{
	size_t		size;

	size = ft_wcharlen(wchar);
	if (size == 1)
		fresh[i++] = (char)wchar;
	else if (size == 2)
	{
		fresh[i++] = (char)(wchar >> 6) + 0xC0;
		fresh[i++] = (char)(wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		fresh[i++] = (char)(wchar >> 12) + 0xE0;
		fresh[i++] = (char)((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (char)(wchar & 0x3F) + 0x80;
	}
	else
	{
		fresh[i++] = (char)(wchar >> 18) + 0xF0;
		fresh[i++] = (char)((wchar >> 12) & 0x3F) + 0x80;
		fresh[i++] = (char)((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (char)(wchar & 0x3F) + 0x80;
	}
	return (i);
}

char	*ft_transform_wchar_in_char(wchar_t *ws)
{
	char	*fresh;
	int		i;
	int		k;
	size_t	len;

	if (!ws)
		return (0);
	i = 0;
	k = 0;
	len = ft_wbytelen(ws);
	if (!(fresh = (char*)malloc(len + 1 * (sizeof(char)))))
		return (NULL);
	fresh[len] = '\0';
	while (ws[k])
	{
		i = ft_putwchar_in_char(ws[k], fresh, i);
		k++;
	}
	return (fresh);
}
