/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:34:46 by wruet-su          #+#    #+#             */
/*   Updated: 2022/11/16 17:05:32 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_p(unsigned long long ptr, int *count)
{
	if (ptr == 0)
		ft_ptr_0(count);
	else
	{
		ft_0x_and_count(count);
		ft_putnbr_p(ptr);
		ft_count_p(ptr, count);
	}
}

void	ft_putnbr_p(unsigned long long ptr)
{
	if (ptr < 16)
		ft_putchar(BASE_HEX_MIN[ptr]);
	else
	{
		ft_putnbr_p(ptr / 16);
		ft_putchar(BASE_HEX_MIN[ptr % 16]);
	}
}

void	ft_0x_and_count(int *count)
{
	write(1, "0x", 2);
	*count = *count + 2;
}

void	ft_count_p(unsigned long long ptr, int *count)
{
	if (ptr == 0)
		*count = *count + 1;
	while (ptr > 0)
	{
		*count = *count + 1;
		ptr = ptr / 16;
	}
}

void	ft_ptr_0(int *count)
{
	write(1, "0x0", 3);
	*count = *count + 3;
}
