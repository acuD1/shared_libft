/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:33:06 by fcatusse          #+#    #+#             */
/*   Updated: 2019/07/19 12:20:44 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

t_printf g_op_tab[] =
{
	{ 'c', fun_c },
	{ 'd', fun_d },
	{ 's', fun_s }
};

void				put_ap(char *ptr, va_list *ap)
{
	t_printf		op_len;
	unsigned long	i;

	i = 0;
	while (g_op_tab[i].flag != *(ptr + 1)
		&& (i < sizeof(g_op_tab) / sizeof(op_len) - 1))
		i++;
	if (i <= sizeof(g_op_tab) / sizeof(op_len) - 1)
		g_op_tab[i].f(ap);
}

void				my_printf(char *format, ...)
{
	va_list			ap;

	va_start(ap, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			put_ap(format, &ap);
			format = format + 2;
		}
		else
			ft_putchar(*format++);
	}
	va_end(ap);
}
