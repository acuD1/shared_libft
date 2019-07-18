/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:21:59 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/07 14:23:37 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void		ft_lstappend(t_lst **alst, t_lst *new)
{
	t_lst	*node;

	if (!new)
		return ;
	node = *alst;
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*alst = new;
}
