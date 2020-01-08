/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:21:59 by arsciand          #+#    #+#             */
/*   Updated: 2020/01/08 18:59:10 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

t_lst	*ft_lstappend(t_lst **alst, t_lst *new)
{
	t_lst	*node;

	if (!new)
		return (NULL);
	node = *alst;
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new;
		new->prev = node; 
	}
	else
		*alst = new;
	return (new);
}
