/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:27:11 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/05 01:57:35 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	g_buff[BUFF_MAX];
size_t	g_i;

void	ft_buf(char c, PF *argument)
{
	g_buff[g_i] = c;
	g_i++;
	if (g_i == BUFF_MAX)
		ft_display(argument);
}

void	*ft_buff(char *str, PF *argument)
{
	while (*str)
	{
		ft_buf(*str, argument);
		str++;
	}
	return (NULL);
}

int8_t	ft_get_flags(PF *argu, va_list ap)
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
		return (FAILURE);
	return (SUCCESS);
}

void	ft_check_format(char *str, PF *argument, va_list ap)
{
	SPE		spe[128];
	size_t	i;

	i = 0;
	ft_init_spe_tab(spe);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_argument(argument);
			argument->format = &str[++i];
			if (ft_get_flags(argument, ap) != SUCCESS)
				return ;
			spe->spe[argument->spec](argument, ap);
			i += argument->index;
		}
		else if (str[i] != '%' && str[i] != '\0')
			ft_buf(str[i], argument);
		i++;
	}
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
