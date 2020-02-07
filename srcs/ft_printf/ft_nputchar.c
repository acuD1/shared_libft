/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:12:13 by guvillat          #+#    #+#             */
/*   Updated: 2020/02/07 00:11:52 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nputchar(char c, ssize_t n, PF *argument)
{
	ssize_t	i;
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	i = 0;
	while (i < n)
	{
		ft_buff(s, argument);
		i++;
	}
}
