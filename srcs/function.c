/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:59:32 by fcatusse          #+#    #+#             */
/*   Updated: 2019/07/19 12:30:26 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void	fun_c(va_list *ap)
{
	ft_putchar(va_arg(*ap, int));
}

void	fun_s(va_list *ap)
{
	ft_putstr(va_arg(*ap, char*));
}

void	fun_d(va_list *ap)
{
	ft_putnbr(va_arg(*ap, int));
}
