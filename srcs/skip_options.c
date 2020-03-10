/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <mpivet-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 03:46:53 by mpivet-p          #+#    #+#             */
/*   Updated: 2020/03/10 18:48:24 by mpivet-p         ###   ########.fr       */
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
			return (i + 1);
		i++;
	}
	return (i);
}
