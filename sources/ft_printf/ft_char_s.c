/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:07:03 by wruet-su          #+#    #+#             */
/*   Updated: 2022/11/16 16:53:57 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_s(char *str, int *count)
{
	if (!str)
		ft_str_null(count);
	else
	{
		ft_putstr(str);
		ft_count_s(str, count);
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_count_s(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	*count = *count + i;
}

void	ft_str_null(int *count)
{
	write(1, "(null)", 6);
	*count = *count + 6;
}
