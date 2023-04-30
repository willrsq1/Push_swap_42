/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_3_stack_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 00:43:48 by root              #+#    #+#             */
/*   Updated: 2022/12/10 00:56:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_size_is_3(t_lst **stack_a, int size, char *r)
{
	t_lst	*lst;

	lst = *stack_a;
	if (ft_lst_is_sorted(lst) == 1)
		return ;
	ft_order(lst, size, stack_a);
	if (lst->order == 3 && lst->next->order == 2)
	{
		ft_swap_a(stack_a, r);
		ft_reverse_rotate_a(stack_a, 0, r);
	}
	else if (lst->order == 3 && lst->next->order == 1)
		ft_rotate_a(stack_a, 0, r);
	else if (lst->order == 2 && lst->next->order == 1)
		ft_swap_a(stack_a, r);
	else if (lst->order == 2 && lst->next->order == 3)
		ft_reverse_rotate_a(stack_a, 0, r);
	else if (lst->order == 1 && lst->next->order == 3)
	{
		ft_reverse_rotate_a(stack_a, 0, r);
		ft_swap_a(stack_a, r);
	}
}
