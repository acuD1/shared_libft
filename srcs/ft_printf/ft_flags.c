/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:26:53 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/05 01:29:45 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_check_width(PF *argu, va_list ap)
{
	size_t	i;
	char	*str;

	i = argu->index;
	if (ft_isdigit(argu->format[argu->index])
		&& argu->format[argu->index] != '0')
	{
		while (ft_isdigit(argu->format[argu->index]))
			argu->index++;
		argu->flags[1] = 0;
		if (argu->index - i > 0)
		{
			str = ft_strsub(argu->format, (unsigned char)i, argu->index - i);
			argu->flags[1] = ft_atoi((const char*)str);
			ft_strdel(&str);
		}
	}
	ft_wildcard(argu, ap, 1);
	return (argu->index);
}

size_t	ft_check_precision(PF *argument, va_list ap)
{
	size_t	i;
	char	*str;
	int		wild;

	if (argument->format[argument->index] == '.')
	{
		i = ++argument->index;
		argument->flags[0] = 0;
		if (argument->format[argument->index] == '*')
			wild = ft_wildcard(argument, ap, 0);
		i = argument->index;
		while (ft_isdigit(argument->format[argument->index]))
			argument->index++;
		if (argument->index - i > 0)
		{
			str = ft_strsub(argument->format,
					(unsigned int)i, argument->index - i);
			argument->flags[0] = ft_atoi((const char*)str);
			ft_strdel(&str);
		}
	}
	return (argument->index);
}

size_t	ft_check_flags(PF *argu)
{
	while (argu->format[argu->index] == '-' || argu->format[argu->index] == '+'
		|| argu->format[argu->index] == ' ' || argu->format[argu->index] == '#'
		|| argu->format[argu->index] == '0')
	{
		if (argu->format[argu->index] == '#')
			argu->flags[2] = 1;
		if (argu->format[argu->index] == '0')
			argu->flags[3] = 1;
		if (argu->format[argu->index] == '-')
			argu->flags[4] = 1;
		if (argu->format[argu->index] == '+')
			argu->flags[5] = 1;
		if (argu->format[argu->index] == ' ')
			argu->flags[6] = 1;
		argu->index++;
	}
	return (argu->index);
}

void	ft_check_length(PF *argu)
{
	while (argu->format[argu->index] == 'h' || argu->format[argu->index] == 'l'
		|| argu->format[argu->index] == 'z' || argu->format[argu->index] == 'j')
	{
		if (argu->format[argu->index] == 'z')
			argu->flags[12] = 1;
		else if (argu->format[argu->index] == 'j')
			argu->flags[11] = 1;
		else if (argu->format[argu->index] == 'h'
			&& argu->format[argu->index + 1] == 'h')
		{
			argu->flags[7] = 1;
			argu->index++;
		}
		else if (argu->format[argu->index] == 'h')
			argu->flags[8] = 1;
		else if (argu->format[argu->index] == 'l'
			&& argu->format[argu->index + 1] == 'l')
		{
			argu->flags[9] = 1;
			argu->index++;
		}
		else if (argu->format[argu->index] == 'l')
			argu->flags[10] = 1;
		argu->index++;
	}
}

size_t	ft_check_spec(PF *argument)
{
	if (argument->format[argument->index] == 's')
		argument->spec = 's';
	else if (argument->format[argument->index] == 'S')
		argument->spec = 'S';
	else if (argument->format[argument->index] == 'p')
		argument->spec = 'p';
	else if (argument->format[argument->index] == 'd')
		argument->spec = 'd';
	else if (argument->format[argument->index] == 'D')
		argument->spec = 'D';
	else if (argument->format[argument->index] == 'i')
		argument->spec = 'i';
	else if (argument->format[argument->index] == 'o')
		argument->spec = 'o';
	else if (argument->format[argument->index] == 'O')
		argument->spec = 'O';
	else if (argument->format[argument->index] == 'u')
		argument->spec = 'u';
	else if (argument->format[argument->index] == 'U')
		argument->spec = 'U';
	else if (argument->format[argument->index] == 'x')
		argument->spec = 'x';
	else if (argument->format[argument->index] == 'X')
		argument->spec = 'X';
	return (ft_check_spec_bis(argument));
}
