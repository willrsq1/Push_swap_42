/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:49:00 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/14 14:49:03 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_push_swap.h"

/* PUSH FUNCTIONS */

/* Pushes the first elem of a stack to the beginning of the other */
/* Removes it from the first */

void	ft_tlst_addfront_checker(t_lst **stack_pushed, t_lst **stack)
{
	t_lst	*to_add;
	t_lst	*new_fst;

	to_add = *stack_pushed;
	if (to_add->next)
	{
		new_fst = to_add->next;
		new_fst->previous = NULL;
		*stack_pushed = new_fst;
	}
	else
		*stack_pushed = NULL;
	new_fst = *stack;
	to_add->next = new_fst;
	if (to_add->next)
		to_add->next->previous = to_add;
	*stack = to_add;
}

/* Pushes the 1st element of B on top of A */

void	ft_push_a_checker(t_lst **stack_b, t_lst **stack_a)
{
	if (*stack_b)
		ft_tlst_addfront_checker(stack_b, stack_a);
}

/* Pushes the 1st element of A on top of B */

void	ft_push_b_checker(t_lst **stack_a, t_lst **stack_b)
{
	if (*stack_a)
		ft_tlst_addfront_checker(stack_a, stack_b);
}
