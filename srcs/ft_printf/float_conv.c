/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:42:32 by guvillat          #+#    #+#             */
/*   Updated: 2019/09/23 15:11:02 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_wildcard(PF *argument, va_list ap, int i)
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

long double		ft_round(long double nbr, int precision)
{
	int			i;
	long double	fl;
	long double	tt;
	uintmax_t	curr;

	curr = 0;
	tt = nbr;
	fl = 1;
	i = 0;
	while (i < precision)
	{
		tt = tt - (uintmax_t)tt;
		tt *= 10;
		curr = (uintmax_t)tt;
		fl /= 10;
		i++;
	}
	if (curr >= 5)
		nbr += fl;
	return (nbr);
}

char			*ft_getipart(long double nf, PF *argument, int precision)
{
	uintmax_t	curr;
	char		*tmp;
	char		*ptr;
	int			i;

	i = 0;
	if (!(tmp = ft_strnew(128)))
		return (NULL);
	while (i < precision)
	{
		nf = nf - (uintmax_t)nf;
		nf *= 10;
		curr = (uintmax_t)nf % 10;
		ptr = ft_itoa_base(curr, 10);
		tmp = ft_strncat(tmp, ptr, 1);
		free(ptr);
		i++;
	}
	argument->arg = ft_strncat(argument->arg, tmp, precision);
	free(tmp);
	return (argument->arg);
}

char			*ft_ftoa(long double nbr, PF *argument, int precision)
{
	uintmax_t	digit;

	digit = nbr * 10;
	digit %= 10;
	if (!precision)
		if (digit >= 5)
			nbr++;
	argument->arg = ft_itoa_base((uintmax_t)nbr, 10);
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

int				float_handler(PF *argument, va_list ap)
{
	long double	n;
	int			precision;

	argument->spec = 'f';
	n = (long double)va_arg(ap, double);
	precision = argument->flags[0];
	if (precision == -1)
		precision = 6;
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
