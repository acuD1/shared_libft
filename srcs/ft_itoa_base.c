/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:10:31 by guvillat          #+#    #+#             */
/*   Updated: 2019/09/23 14:11:12 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"
#include <stdint.h>

char	*ft_itoa_base(uintmax_t nbr, int base)
{
	static char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F'};
	uintmax_t	n;
	intmax_t	i;
	int			converted_nbr[64];
	char		*str;

	if (nbr == 0)
		return (ft_strdup("0"));
	i = 0;
	n = (intmax_t)nbr;
	while (n > 0)
	{
		converted_nbr[i++] = n % base;
		n /= base;
	}
	if (!(str = (char*)malloc(sizeof(char *) * --i)))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
		str[n++] = hex[converted_nbr[i--]];
	return (str);
}
