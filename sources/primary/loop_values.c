/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:14:36 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 14:13:18 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* This sets in a struct the params that will be used. */

void	ft_set_loops_params(t_lst2 *l, int argc, char **argv)
{
	l->argc = argc;
	l->argv = argv;
	if ((QUICK == 2 && argc <= 350) || (QUICK == 4 && argc > 350))
	{
		l->margin = 30;
		l->max1 = 42;
		l->i_value = 4;
		l->i_max = 11;
		l->aloha_min = 6;
		l->aloha_max = 13;
		l->w = 0;
	}
	else if (QUICK == 2 && argc > 350)
	{
		l->margin = 69;
		l->max1 = 71;
		l->i_value = 12;
		l->i_max = 17;
		l->aloha_min = 13;
		l->aloha_max = 17;
		l->w = 0;
	}
	else
		ft_set_loops_params2(l, argc);
}

void	ft_set_loops_params2(t_lst2 *l, int argc)
{	
	if (argc > 350 && QUICK == 3)
	{
		l->margin = 64;
		l->max1 = 75;
		l->i_value = 11;
		l->i_max = 19;
		l->aloha_min = 12;
		l->aloha_max = 19;
		l->w = 0;
	}
	else if (QUICK == 3 || (QUICK == 5 && argc > 350))
	{
		l->margin = 29;
		l->max1 = 43;
		l->i_value = 3;
		l->i_max = 15;
		l->aloha_min = 3;
		l->aloha_max = 15;
		l->w = 0;
	}
	else
		ft_set_loops_params3(l);
}

void	ft_set_loops_params3(t_lst2 *l)
{
	if (QUICK == 4)
	{
		l->margin = 5;
		l->max1 = 47;
		l->i_value = -2;
		l->i_max = 20;
		l->aloha_min = -2;
		l->aloha_max = 22;
		l->w = 0;
	}
	else
	{
		l->margin = 0;
		l->max1 = 52;
		l->i_value = -1;
		l->i_max = 25;
		l->aloha_min = -1;
		l->aloha_max = 25;
		l->w = 0;
	}
}
