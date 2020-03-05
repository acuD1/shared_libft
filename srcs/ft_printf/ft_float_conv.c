/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:42:32 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/05 01:30:34 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_wildcard(PF *argument, va_list ap, int i)
{
	if (argument->format[argument->index] == '*')
	{
		argument->flags[i] = va_arg(ap, int);
		if (argument->flags[i] < 0)
		{
			if (i == 1)
			{
				argument->flags[4] = 1;
				argument->flags[1] *= -1;
			}
			else if (i == 0)
			{
				argument->flags[0] = -1;
				argument->index++;
				return (0);
			}
		}
		argument->index++;
	}
	return (1);
}

static long double	ft_round(long double nbr, size_t precision)
{
	size_t		i;
	long double	fl;
	long double	tt;
	u_int64_t	curr;

	curr = 0;
	tt = nbr;
	fl = 1;
	i = 0;
	while (i < precision)
	{
		tt = tt - (u_int64_t)tt;
		tt *= 10;
		curr = (u_int64_t)tt;
		fl /= 10;
		i++;
	}
	if (curr >= 5)
		nbr += fl;
	return (nbr);
}

static char			*ft_getipart(long double nf, PF *argument, size_t precision)
{
	u_int64_t	curr;
	char		*tmp;
	char		*ptr;
	size_t		i;

	i = 0;
	if (!(tmp = ft_strnew(128)))
		return (NULL);
	while (i < precision)
	{
		nf = nf - (u_int64_t)nf;
		nf *= 10;
		curr = (u_int64_t)nf % 10;
		ptr = ft_itoa_base_custom(curr, 10);
		tmp = ft_strncat(tmp, ptr, 1);
		ft_strdel(&ptr);
		i++;
	}
	argument->arg = ft_strncat(argument->arg, tmp, precision);
	ft_strdel(&tmp);
	return (argument->arg);
}

static char			*ft_ftoa(long double nbr, PF *argument, size_t precision)
{
	u_int64_t	digit;

	digit = (u_int64_t)nbr * 10;
	digit %= 10;
	if (!precision)
		if (digit >= 5)
			nbr++;
	argument->arg = ft_itoa_base_custom((u_int64_t)nbr, 10);
	if (precision || argument->flags[2])
		argument->arg = ft_strncat(argument->arg, ".", 1);
	if (precision)
	{
		nbr = ft_round(nbr, precision);
		argument->arg = ft_getipart(nbr, argument, precision);
	}
	argument->flags[0] = -1;
	return (argument->arg);
}

int					float_handler(PF *argument, va_list ap)
{
	long double	n;
	size_t		precision;

	argument->spec = 'f';
	n = (long double)va_arg(ap, double);
	if (argument->flags[0] == -1)
		precision = 6;
	else
		precision = (size_t)argument->flags[0];
	if (n >= 0)
		argument->arg = ft_ftoa(n, argument, precision);
	else if (n < 0)
	{
		argument->arg = ft_ftoa(-n, argument, precision);
		return (ft_print_number(argument, "-"));
	}
	if (argument->flags[5])
		return (ft_print_number(argument, "+"));
	if (argument->flags[6])
		return (ft_print_number(argument, " "));
	return (ft_print_number(argument, ""));
}
