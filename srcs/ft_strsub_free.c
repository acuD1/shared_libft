/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:07:30 by arsciand          #+#    #+#             */
/*   Updated: 2020/03/05 01:14:39 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	*ft_strsub_free(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	char	*tmp;
	size_t	i;

	tmp = NULL;
	if (!s)
		return (NULL);
	tmp = (char*)s;
	if (!(fresh = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	while (len > 0)
	{
		fresh[i] = s[start];
		i++;
		start++;
		len--;
	}
	free(tmp);
	return (fresh);
}
