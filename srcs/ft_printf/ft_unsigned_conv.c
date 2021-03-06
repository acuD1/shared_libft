/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:27:51 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/05 03:03:19 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static u_int64_t	unsigned_cast(PF *argument, va_list ap)
{
	u_int64_t			n;

	n = va_arg(ap, u_int64_t);
	if (argument->flags[7] == 1)
		n = (unsigned char)(n);
	else if (argument->flags[8] == 1)
		n = (unsigned short)(n);
	else if (argument->flags[10] == 1)
		n = (unsigned long)(n);
	else if (argument->flags[9] == 1)
		n = (unsigned long long)(n);
	else if (argument->flags[11] == 1)
		n = (u_int64_t)(n);
	else if (argument->flags[12] == 1)
		n = (size_t)(n);
	else
		n = (unsigned int)(n);
	return (n);
}

static u_int8_t		unsigned_helper(PF *argument)
{
	ssize_t				len;
	int					nullstr;

	len = (ssize_t)ft_strlen(argument->arg);
	nullstr = (len == 1 && !ft_strcmp(argument->arg, "0")) ? 0 : 1;
	if (argument->flags[2] == 1)
	{
		if (argument->spec == 'o' || argument->spec == 'O')
		{
			if (argument->flags[0] <= len && ft_strcmp(argument->arg, "0") != 0)
				return (ft_print_number(argument, "0"));
		}
		else if (argument->spec == 'x' && nullstr != 0)
			return (ft_print_number(argument, "0x"));
		else if (argument->spec == 'X' && nullstr != 0)
			return (ft_print_number(argument, "0X"));
	}
	return (ft_print_number(argument, ""));
}

u_int8_t			unsigned_handler(PF *argument, va_list ap)
{
	u_int64_t			n;

	if (argument->spec == 'x' || argument->spec == 'X'
		|| argument->spec == 'u' || argument->spec == 'o'
		|| argument->spec == 'b')
		n = unsigned_cast(argument, ap);
	else
		n = (unsigned long int)va_arg(ap, u_int64_t);
	if (argument->spec == 'o' || argument->spec == 'O')
		argument->arg = ft_itoa_base_custom(n, 8);
	else if (argument->spec == 'u' || argument->spec == 'U')
		argument->arg = ft_itoa_base_custom(n, 10);
	else if (argument->spec == 'x')
		argument->arg = ft_strlower(ft_itoa_base_custom(n, 16));
	else if (argument->spec == 'b')
		argument->arg = ft_itoa_base_custom(n, 2);
	else
		argument->arg = ft_itoa_base_custom(n, 16);
	return (unsigned_helper(argument));
}

u_int8_t			prc_handler(PF *argument, va_list ap)
{
	argument->arg = "%";
	ft_print_character(argument);
	return ((u_int8_t)ap);
}

u_int8_t			pointer_handler(PF *argument, va_list ap)
{
	u_int64_t			n;

	n = va_arg(ap, u_int64_t);
	argument->arg = ft_itoa_base_custom(n, 16);
	argument->arg = ft_strlower(argument->arg);
	return (ft_print_number(argument, "0x"));
}
