/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:37:01 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/09/25 19:50:52 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
