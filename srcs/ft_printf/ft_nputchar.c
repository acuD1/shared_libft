/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:12:13 by guvillat          #+#    #+#             */
/*   Updated: 2019/01/23 15:12:18 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_nputchar(char c, ssize_t n, PF *argument)
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
