/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:27:11 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/02 16:51:03 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_buf(char c, PF *argument)
{
	g_buff[g_i] = c;
	g_i++;
	if (g_i == BUFF_MAX)
		ft_display(argument);
}

void	*ft_buff(char *str, PF *argument)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_buf(str[i++], argument);
	return (NULL);
}

int		ft_get_flags(PF *argu, va_list ap)
{
	argu->index = 0;
	while (argu->format[argu->index] == '#' || argu->format[argu->index] == '0'
		|| argu->format[argu->index] == '-' || argu->format[argu->index] == '+'
		|| argu->format[argu->index] == ' ' || argu->format[argu->index] == 'h'
		|| argu->format[argu->index] == 'l' || argu->format[argu->index] == 'j'
		|| argu->format[argu->index] == 'z' || argu->format[argu->index] == '.'
		|| argu->format[argu->index] == '*' ||
		ft_isdigit(argu->format[argu->index]))
	{
		ft_check_flags(argu);
		ft_check_width(argu, ap);
		ft_check_precision(argu, ap);
		ft_check_length(argu);
	}
	ft_check_spec(argu);
	if (argu->index == ft_strlen(argu->format))
		return (-1);
	return (argu->index);
}

int		ft_check_format(char *str, PF *argument, va_list ap)
{
	int i;
	SPE spe[128];

	i = -1;
	ft_init_spe_tab(spe);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_argument(argument);
			argument->format = &str[++i];
			if (ft_get_flags(argument, ap) == -1)
				return (-1);
			spe->spe[argument->spec](argument, ap);
			i += argument->index;
		}
		else if (str[i] != '%' && str[i] != '\0')
			ft_buf(str[i], argument);
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	PF		argument;

	if (!format)
		return (-1);
	g_i = 0;
	argument.ret = 0;
	argument.fd = STDOUT_FILENO;
	va_start(ap, format);
	ft_init_argument(&argument);
	argument.fd = 1;
	ft_init_buff();
	ft_check_format((char*)format, &argument, ap);
	if (g_i)
		ft_display(&argument);
	va_end(ap);
	return (argument.ret);
}
