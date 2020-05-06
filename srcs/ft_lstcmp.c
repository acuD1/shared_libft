/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <fcatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:42:06 by fcatusse          #+#    #+#             */
/*   Updated: 2020/05/06 19:42:36 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

int		ft_lstcmp(t_lst *lst1, t_lst *lst2, int (*f)(void *, void *))
{
	if (!lst1 && !lst2)
		return (0);
	if ((lst1 && !lst2) || (!lst1 && lst2))
		return (-1);
	if (f(lst1->content, lst2->content))
		return (-1);
	return (ft_lstcmp(lst1->next, lst2->next, f));
}
