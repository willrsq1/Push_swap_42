/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:48:02 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/14 14:48:06 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_push_swap.h"

/* SWAP FUNCTIONS */

/* Swaps stack A's first 2 elements */

void	ft_swap_a_checker(t_lst **stack)
{
	t_lst	*first;
	int		swap;

	first = *stack;
	if (first && first->next)
	{
		swap = first->content;
		first->content = first->next->content;
		first->next->content = swap;
	}
}

/* Swaps stack B's first 2 elements */

void	ft_swap_b_checker(t_lst **stack)
{
	t_lst	*first;
	int		swap;

	first = *stack;
	if (first && first->next)
	{
		swap = first->content;
		first->content = first->next->content;
		first->next->content = swap;
	}
}

/* Does both SA & SB */

void	ft_swap_a_and_b_checker(t_lst **stack_a, t_lst **stack_b)
{
	ft_swap_a_checker(stack_a);
	ft_swap_b_checker(stack_b);
}
