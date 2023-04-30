/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:07:46 by wruet-su          #+#    #+#             */
/*   Updated: 2022/11/16 17:12:41 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_dispatch(va_list varl, int *count, char c);
void	ft_dir(va_list varl, int *count, char *str);
int		ft_printf(const char *str, ...);
/* specific main functions*/
void	ft_char_c(char c, int *count);
void	ft_char_s(char *str, int *count);
void	ft_char_p(unsigned long long ptr, int *count);
void	ft_char_d(int nb, int *count);
void	ft_char_u(unsigned int nb, int *count);
void	ft_char_x(unsigned int nb, int *count);
void	ft_char_xx(unsigned int nb, int *count);
/*specific printing functions*/
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putnbr_p(unsigned long long ptr);
void	ft_putnbr_unsigned(unsigned int nb);
void	ft_putnbr_x(unsigned int nb);
void	ft_putnbr_xx(unsigned int nb);
/*specific counting functions*/
void	ft_count_c(int *count);
void	ft_count_s(char *str, int *count);
void	ft_count_p(unsigned long long ptr, int *count);
void	ft_count_d(int nb, int *count);
void	ft_count_u(unsigned int nb, int *count);
void	ft_count_x(unsigned int nb, int *count);
void	ft_count_xx(unsigned int nb, int *count);
/*utilitary functions*/
void	ft_0x_and_count(int *count);
void	ft_putchar(char c);
void	ft_str_null(int *count);
void	ft_ptr_0(int *count);

# ifndef BASE_HEX_MIN
#  define BASE_HEX_MIN "0123456789abcdef"
# endif

# ifndef BASE_HEX_MAJ
#  define BASE_HEX_MAJ "0123456789ABCDEF"
# endif
#endif
