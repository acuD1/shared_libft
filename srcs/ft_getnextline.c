/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:52:53 by arsciand          #+#    #+#             */
/*   Updated: 2020/03/08 13:56:05 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"
#include <unistd.h>
#include <stdlib.h>

static int32_t	check_line(char **stack)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = *stack;
	while (tmp[i] != '\n')
		if (!(tmp[i++]))
			return (0);
	return (1);
}

static int32_t	init(const int fd, char **line, char *buff, char **stack)
{
	if (fd == -1 || FD_MAXSET > 4864 || BUFF_SZ < 1
			|| !line || read(fd, buff, 0))
		return (0);
	if (!(stack[fd]))
		if (!(stack[fd] = ft_strnew(0)))
			return (0);
	return (1);
}

int32_t			ft_getnextline(const int fd, char **line)
{
	static char	*stack[FD_MAXSET];
	char		*buff;
	char		*tmp;
	ssize_t		ret;

	if (!(buff = ft_memalloc(BUFF_SZ + 1)) || (!init(fd, line, buff, stack)))
		return (-1);
	while (!(check_line(&stack[fd])) && (ret = read(fd, buff, BUFF_SZ)))
	{
		buff[ret] = '\0';
		tmp = stack[fd];
		stack[fd] = ft_strjoinf(tmp, buff, 1);
	}
	free(buff);
	*line = ft_strsub(stack[fd], 0, ft_strclen(stack[fd], '\n'));
	if (*stack[fd])
	{
		if (check_line(&stack[fd]))
			ft_strcpy(stack[fd], ft_strchr(stack[fd], '\n') + 1);
		else
			ft_strdel(&stack[fd]);
		return (1);
	}
	free(stack[fd]);
	return (0);
}
