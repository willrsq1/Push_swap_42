/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_XX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:07:11 by wruet-su          #+#    #+#             */
/*   Updated: 2022/11/16 17:05:43 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_xx(unsigned int nb, int *count)
{
	ft_putnbr_xx(nb);
	ft_count_xx(nb, count);
}

void	ft_putnbr_xx(unsigned int nb)
{
	if (nb < 16)
		ft_putchar(BASE_HEX_MAJ[nb]);
	else
	{
		ft_putnbr_xx(nb / 16);
		ft_putchar(BASE_HEX_MAJ[nb % 16]);
	}
}

void	ft_count_xx(unsigned int nb, int *count)
{
	if (nb == 0)
		*count = *count + 1;
	while (nb > 0)
	{
		*count = *count + 1;
		nb = nb / 16;
	}
}
