/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:46:40 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/09 11:05:57 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	*ft_strjoinf(char *s1, char *s2, uint8_t vars)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (vars == 0)
		return (str);
	else if (vars == 1)
		free(s1);
	else if (vars == 2)
		free(s2);
	else
	{
		free(s1);
		free(s2);
	}
	return (str);
}
