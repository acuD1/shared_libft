/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:26:34 by guvillat          #+#    #+#             */
/*   Updated: 2020/02/07 00:11:42 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	PF		argument;

	if (!format)
		return (-1);
	g_i = 0;
	argument.ret = 0;
	va_start(ap, format);
	ft_init_argument(&argument);
	ft_init_buff();
	argument.fd = fd;
	ft_check_format((char*)format, &argument, ap);
	if (g_i)
		ft_display(&argument);
	va_end(ap);
	return (argument.ret);
}
