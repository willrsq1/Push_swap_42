/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:08:00 by wruet-su          #+#    #+#             */
/*   Updated: 2022/11/16 16:57:29 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_printf(const char *str, ...)
{
	va_list		varl;
	int			count;

	count = 0;
	va_start(varl, str);
	ft_dir(varl, &count, (char *)str);
	va_end(varl);
	return (count);
}

void	ft_dir(va_list varl, int *count, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ft_dispatch(varl, count, str[i]);
			if (str[i] == '%')
			{
				write(1, "%", 1);
				*count = *count + 1;
			}
		}
		else
		{
			write(1, &str[i], 1);
			*count = *count + 1;
		}
		i++;
	}
}

void	ft_dispatch(va_list varl, int *count, char c)
{
	if (c == 'c')
		ft_char_c(va_arg(varl, int), count);
	else if (c == 's')
		ft_char_s(va_arg(varl, char *), count);
	else if (c == 'p')
		ft_char_p(va_arg(varl, unsigned long long), count);
	else if (c == 'd' || c == 'i')
		ft_char_d(va_arg(varl, int), count);
	else if (c == 'u')
		ft_char_u(va_arg(varl, unsigned int), count);
	else if (c == 'x')
		ft_char_x(va_arg(varl, unsigned int), count);
	else if (c == 'X')
		ft_char_xx(va_arg(varl, unsigned int), count);
}
