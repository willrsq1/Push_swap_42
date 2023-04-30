/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:07:26 by wruet-su          #+#    #+#             */
/*   Updated: 2022/11/16 17:04:56 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_x(unsigned int nb, int *count)
{
	ft_putnbr_x(nb);
	ft_count_x(nb, count);
}

void	ft_putnbr_x(unsigned int nb)
{
	if (nb < 16)
		ft_putchar(BASE_HEX_MIN[nb]);
	else
	{
		ft_putnbr_x(nb / 16);
		ft_putchar(BASE_HEX_MIN[nb % 16]);
	}
}

void	ft_count_x(unsigned int nb, int *count)
{
	if (nb == 0)
		*count = *count + 1;
	while (nb > 0)
	{
		*count = *count + 1;
		nb = nb / 16;
	}
}
