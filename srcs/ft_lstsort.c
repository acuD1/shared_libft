/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <fcatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:35:27 by fcatusse          #+#    #+#             */
/*   Updated: 2020/05/06 19:38:35 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

static t_lst	*merge_lists(t_lst *a, t_lst *b, int (*cmp)(void *, void *))
{
	t_lst		*merged_list;

	merged_list = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (cmp(a->content, b->content) <= 0)
	{
		merged_list = a;
		merged_list->next = merge_lists(a->next, b, cmp);
	}
	else
	{
		merged_list = b;
		merged_list->next = merge_lists(a, b->next, cmp);
	}
	return (merged_list);
}

static void		partition(t_lst *lst, t_lst **front, t_lst **back)
{
	t_lst		*fast;
	t_lst		*slow;

	*front = lst;
	if (!lst || !lst->next)
		*back = NULL;
	else
	{
		slow = lst;
		fast = lst->next;
		while (fast)
		{
			if ((fast = fast->next))
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*back = slow->next;
		slow->next = NULL;
	}
}

void			ft_lstsort(t_lst **lst, int (*cmp)(void *, void *))
{
	t_lst		*head;
	t_lst		*a;
	t_lst		*b;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	head = *lst;
	a = NULL;
	b = NULL;
	partition(head, &a, &b);
	ft_lstsort(&a, cmp);
	ft_lstsort(&b, cmp);
	*lst = merge_lists(a, b, cmp);
}
