/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 03:46:53 by mpivet-p          #+#    #+#             */
/*   Updated: 2020/03/05 01:18:05 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

size_t	skip_opt(char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--"))
			return (i);
		i++;
	}
	return (i);
}
