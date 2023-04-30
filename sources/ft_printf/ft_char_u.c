/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:21:09 by wruet-su          #+#    #+#             */
/*   Updated: 2022/11/15 21:41:51 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_u(unsigned int nb, int *count)
{
	ft_putnbr_unsigned(nb);
	ft_count_u(nb, count);
}

void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

void	ft_count_u(unsigned int nb, int *count)
{
	if (nb == 0)
		*count = *count + 1;
	while (nb > 0)
	{
		nb = nb / 10;
		*count = *count + 1;
	}
}
