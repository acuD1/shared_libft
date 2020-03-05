/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:26:27 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/05 03:02:02 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

u_int8_t		ft_arg_nospe(PF *argument, va_list ap)
{
	char	c[2];

	c[0] = (char)argument->spec;
	c[1] = '\0';
	argument->arg = c;
	ft_print_character(argument);
	return ((u_int8_t)ap);
}

static u_int8_t	wchar_handler(va_list ap, PF *argument)
{
	wint_t	c;

	c = (wint_t)va_arg(ap, wint_t);
	argument->spec = 'C';
	if (c == 0)
	{
		if (argument->flags[4])
			g_i++;
		ft_nputchar(' ', argument->flags[1] - 1, argument);
		if (!argument->flags[4])
			g_i++;
		return (0);
	}
	if (!(argument->arg = ft_strnew(4)))
		return (0);
	ft_wchartostr(argument->arg, (wint_t)c);
	ft_print_str(argument);
	return (0);
}

u_int8_t		character_handler(PF *argument, va_list ap)
{
	char	c[2];

	if (argument->spec == 'C' || argument->flags[10] == 1)
		return (wchar_handler(ap, argument));
	c[0] = (char)va_arg(ap, int);
	c[1] = '\0';
	argument->arg = c;
	ft_print_character(argument);
	return (0);
}

ssize_t			ft_print_character(PF *argument)
{
	ssize_t	len;
	ssize_t	padding;

	len = 1;
	padding = 0;
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && argument->flags[3] == 0)
		ft_nputchar(' ', padding, argument);
	if (argument->flags[3] == 1 && argument->flags[4] == 0)
		ft_nputchar('0', padding, argument);
	if (!argument->arg || argument->arg[0] == 0)
		g_i++;
	else
		ft_buff(argument->arg, argument);
	if (argument->flags[4] == 1)
		ft_nputchar(' ', padding, argument);
	return (len);
}
