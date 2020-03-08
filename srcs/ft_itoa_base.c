/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:10:31 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/08 13:29:26 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"
#include <stdlib.h>

static char	*fill_str
	(char *hex, u_int64_t converted_nbr[], int64_t i, int32_t z)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char *) * (u_int64_t)i)))
		return (NULL);
	str[i--] = '\0';
	if (z == 1)
	{
		i--;
		str[0] = '-';
	}
	while (i >= 0 && str[z])
	{
		str[z] = hex[converted_nbr[i--]];
		z++;
	}
	return (str);
}

char		*ft_itoa_base(int32_t nbr, int32_t base)
{
	static char	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F'};
	u_int64_t	converted_nbr[64];
	u_int64_t	n;
	int64_t		i;

	if (base < 2 || base > 16)
		return (NULL);
	if (nbr == 0)
		return (ft_strdup("0"));
	i = 0;
	n = (nbr > 0 ? (u_int64_t)nbr : -(u_int64_t)nbr);
	while (n > 0)
	{
		converted_nbr[i++] = n % (u_int64_t)base;
		n /= (u_int64_t)base;
	}
	n = (nbr < 0 && base == 10) ? 1 : 0;
	if (n)
		i++;
	return (fill_str(hex, converted_nbr, i, (int)n));
}
