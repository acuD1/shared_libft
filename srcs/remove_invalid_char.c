/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_invalid_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:53:19 by mpivet-p          #+#    #+#             */
/*   Updated: 2020/03/05 01:17:40 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

/*
**	Only working with BUFF_SIZE
*/

static void		move_till_end(char *buff, size_t i)
{
	while (i < BUFF_MAX)
	{
		buff[i] = buff[i + 1];
		i++;
	}
}

static u_int8_t	is_done(char *buff, size_t i)
{
	while (i < BUFF_MAX)
	{
		if (buff[i] > 0)
			return (0);
		i++;
	}
	return (1);
}

void			remove_invalid_char(char *buff)
{
	size_t	i;

	i = 0;
	while (i < BUFF_MAX)
	{
		while (buff[i] < 1)
		{
			move_till_end(buff, i);
			if (is_done(buff, i))
				break ;
		}
		i++;
	}
	buff[i] = 0;
}
