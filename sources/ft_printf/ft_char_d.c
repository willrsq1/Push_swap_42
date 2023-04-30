/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:07:20 by wruet-su          #+#    #+#             */
/*   Updated: 2022/11/15 21:42:20 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_d(int nb, int *count)
{
	ft_putnbr(nb);
	ft_count_d(nb, count);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(nb + 2294967296);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

void	ft_count_d(int nb, int *count)
{
	if (nb == -2147483648)
		*count = *count + 11;
	else if (nb < 0)
	{
		nb = nb * -1;
		*count = *count + 1;
	}
	else if (nb == 0)
		*count = *count + 1;
	while (nb > 0)
	{
		*count = *count + 1;
		nb = nb / 10;
	}
}
