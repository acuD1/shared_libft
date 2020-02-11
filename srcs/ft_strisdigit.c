/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:59:58 by guvillat          #+#    #+#             */
/*   Updated: 2020/02/11 15:04:31 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

int ft_strisdigit(const char *str)
{
	int index;

	index = 0;
	if (str)
	{
		while (str[index])
		{
			if (ft_isdigit(str[index]))
				index++;
			else
				return (0);
		}
	}
	return (index);
}
