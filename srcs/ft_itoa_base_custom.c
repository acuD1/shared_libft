/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_custom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:05:17 by arsciand          #+#    #+#             */
/*   Updated: 2020/03/08 13:29:50 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"
#include <stdlib.h>

char	*ft_itoa_base_custom(u_int64_t nbr, int32_t base)
{
	static char	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F'};
	char		*str;
	u_int64_t	converted_nbr[64];
	u_int64_t	n;
	int64_t		i;

	if (nbr == 0)
		return (ft_strdup("0"));
	i = 0;
	n = (u_int64_t)nbr;
	while (n > 0)
	{
		converted_nbr[i++] = n % (u_int64_t)base;
		n /= (u_int64_t)base;
	}
	if (!(str = (char*)malloc(sizeof(char *) * (u_int64_t)i)))
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
		str[n++] = hex[converted_nbr[i--]];
	return (str);
}
