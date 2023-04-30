/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:06:49 by wruet-su          #+#    #+#             */
/*   Updated: 2022/11/16 17:02:07 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_c(char c, int *count)
{
	ft_putchar(c);
	ft_count_c(count);
}

void	ft_count_c(int *count)
{
	*count = *count + 1;
}
