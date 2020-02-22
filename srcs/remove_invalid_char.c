/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_invalid_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:53:19 by mpivet-p          #+#    #+#             */
/*   Updated: 2020/02/22 19:04:07 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

/*
**	Only working with BUFF_SIZE
*/

static void	move_till_end(char *buff, int i)
{
	while (i < BUFF_MAX)
	{
		buff[i] = buff[i + 1];
		i++;
	}
}

static int	is_done(char *buff, int i)
{
	while (i < BUFF_MAX)
	{
		if (buff[i] > 0)
			return (0);
		i++;
	}
	return (1);
}

void		remove_invalid_char(char *buff)
{
	int	i;

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
