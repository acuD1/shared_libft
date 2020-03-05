/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:49:23 by arsciand          #+#    #+#             */
/*   Updated: 2020/03/05 01:22:35 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

static size_t	count_n_len(int32_t n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void		do_conv(char *buffer, long n, size_t i)
{
	if (n > 0)
	{
		do_conv(buffer, n / 10, --i);
		buffer[i] = n % 10 + '0';
	}
}

char			*ft_itoa(int32_t n)
{
	char	s[12];
	size_t	len;

	ft_bzero(s, 12);
	len = count_n_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		s[0] = '-';
		do_conv(s + 1, -(long)n, len);
	}
	else
		do_conv(s + 0, (long)n, len);
	return (ft_strdup(s));
}
