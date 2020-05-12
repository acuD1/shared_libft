/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:43:41 by mpivet-p          #+#    #+#             */
/*   Updated: 2020/03/05 01:31:45 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void		my_cat(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

static u_int8_t	read_line(char **line, char *buffer, int fd, char *tmp)
{
	char	*tml;
	ssize_t	ret;
	size_t	i;

	i = 0;
	while ((ret = read(fd, buffer, BUFF_MAX)) > 0)
	{
		remove_invalid_char(buffer);
		if (ft_strchr(buffer, '\n') != NULL)
		{
			i = (size_t)(ft_strchr(buffer, '\n') - buffer);
			tml = ft_strsub(buffer, 0, i);
			tmp = ft_strjoin(*line, tml);
			my_cat(buffer, buffer + i + 1);
			ft_strdel(line);
			ft_strdel(&tml);
			*line = tmp;
			return (1);
		}
		tmp = ft_strjoin(*line, buffer);
		ft_strdel(line);
		*line = tmp;
		ft_bzero(buffer, BUFF_MAX);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	buffer[BUFF_MAX + 1];
	char		*tmp;
	size_t		i;

	tmp = NULL;
	i = 0;
	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	if (ft_strchr(buffer, '\n') != NULL)
	{
		i = (size_t)(ft_strchr(buffer, '\n') - buffer);
		*line = ft_strsub(buffer, 0, i);
		my_cat(buffer, buffer + i + 1);
		return (1);
	}
	if (buffer[0] != 0)
		*line = ft_strdup(buffer);
	ft_bzero(buffer, BUFF_MAX);
	return (read_line(line, buffer, fd, tmp));
}
