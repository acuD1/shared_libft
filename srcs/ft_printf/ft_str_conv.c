/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:27:43 by guvillat          #+#    #+#             */
/*   Updated: 2020/03/02 16:50:29 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_display(PF *argument)
{
	argument->ret += write(argument->fd, &g_buff, g_i);
	ft_init_buff();
}

static int		wstring_handler(PF *argument, va_list ap)
{
	ssize_t len;

	argument->warg = va_arg(ap, wchar_t *);
	argument->spec = 'S';
	if (!argument->warg)
		argument->warg = L"(null)";
	len = ft_wbytelen(argument->warg);
	if (argument->flags[0] > -1 && argument->flags[0] < len)
		argument->arg = ft_wstrsub(argument->warg, 0, argument->flags[0]);
	else
		argument->arg = ft_transform_wchar_in_char(argument->warg);
	return (ft_print_str(argument));
}

int				string_handler(PF *argument, va_list ap)
{
	ssize_t len;
	char	*tmp;

	if (argument->spec == 'S' || argument->flags[10] == 1)
		return (wstring_handler(argument, ap));
	tmp = va_arg(ap, char *);
	if (!tmp)
		argument->arg = ft_strdup("(null)");
	else
	{
		len = ft_strlen(tmp);
		if (argument->flags[0] > -1 && argument->flags[0] < len)
			argument->arg = ft_strsub(tmp, 0, argument->flags[0]);
		else
			argument->arg = ft_strdup(tmp);
	}
	return (ft_print_str(argument));
}

int				ft_print_str(PF *argument)
{
	ssize_t		len;
	ssize_t		padding;
	int			i;

	i = -1;
	if (!argument->arg)
		return (-1);
	len = (ssize_t)ft_strlen(argument->arg);
	padding = 0;
	if (argument->flags[0] > -1 && argument->flags[0] < len)
		len = argument->flags[0];
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && argument->flags[3] == 0)
		ft_nputchar(' ', padding, argument);
	if (argument->flags[3] == 1 && argument->flags[4] == 0)
		ft_nputchar('0', padding, argument);
	ft_buff(argument->arg, argument);
	if (argument->flags[4] == 1)
		ft_nputchar(' ', padding, argument);
	ft_strdel(&argument->arg);
	return (0);
}