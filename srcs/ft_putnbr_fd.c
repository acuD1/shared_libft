/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:06:12 by fcatusse          #+#    #+#             */
/*   Updated: 2020/03/05 01:23:06 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

void	ft_putnbr_fd(int32_t n, int fd)
{
	long	nb;

	nb = (int32_t)n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_fd((int32_t)(nb / 10), fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}
