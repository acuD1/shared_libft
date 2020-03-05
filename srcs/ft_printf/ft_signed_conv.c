/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:27:37 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/05 03:02:43 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int64_t	signed_cast(PF *argument, va_list ap)
{
	int64_t	n;

	n = va_arg(ap, int64_t);
	if (argument->flags[12] == 1)
		return (n);
	else if (argument->flags[11] == 1)
		return (n);
	else if (argument->flags[9] == 1)
		n = (int64_t)n;
	else if (argument->flags[10] == 1)
		n = (long)n;
	else if (argument->flags[8] == 1)
		n = (int16_t)n;
	else if (argument->flags[7] == 1)
		n = (char)n;
	else
		n = (int32_t)n;
	return (n);
}

static void		test_string(PF *args)
{
	u_int8_t	octal;

	if (!args->arg)
		return ;
	octal = 0;
	if (args->spec == 'o' || args->spec == 'O')
		octal = 1;
	if (args->arg[0] == '0' && !args->arg[1] && args->flags[0] == 0)
	{
		if (!octal || (octal && !args->flags[2]))
		{
			ft_strdel(&args->arg);
			args->arg = ft_strdup("");
		}
	}
}

u_int8_t		signed_handler(PF *argument, va_list ap)
{
	int64_t	n;

	n = (argument->spec == 'd' || argument->spec == 'i') ?
	signed_cast(argument, ap) : (long int)va_arg(ap, int64_t);
	if (n >= 0)
		argument->arg = ft_itoa_base_custom((u_int64_t)n, 10);
	else if (n < 0)
	{
		argument->arg = ft_itoa_base_custom(-(u_int64_t)n, 10);
		return (ft_print_number(argument, "-"));
	}
	if (argument->flags[5])
		return (ft_print_number(argument, "+"));
	if (argument->flags[6])
		return (ft_print_number(argument, " "));
	return (ft_print_number(argument, ""));
}

static u_int8_t	ft_print_number_bis(PF *argument, ssize_t padding)
{
	ft_buff(argument->arg, argument);
	if (argument->flags[4] == 1)
		ft_nputchar(' ', padding, argument);
	ft_strdel(&argument->arg);
	return (0);
}

u_int8_t		ft_print_number(PF *argument, char *pre)
{
	ssize_t	len;
	ssize_t	precision;
	ssize_t	padding;

	test_string(argument);
	len = (ssize_t)ft_strlen(argument->arg);
	precision = 0;
	padding = 0;
	if (argument->flags[0] > len)
		precision = (ssize_t)argument->flags[0] - len;
	len += (ssize_t)ft_strlen(pre) + precision;
	if (argument->flags[1] > len)
		padding = (ssize_t)argument->flags[1] - len;
	if (argument->flags[4] == 0 && (argument->flags[3] == 0
		|| argument->flags[0] != -1))
		ft_nputchar(' ', padding, argument);
	ft_buff(pre, argument);
	if (argument->flags[3] == 1 && argument->flags[4] == 0
		&& argument->flags[0] == -1)
		ft_nputchar('0', padding, argument);
	ft_nputchar('0', precision, argument);
	return (ft_print_number_bis(argument, padding));
}
