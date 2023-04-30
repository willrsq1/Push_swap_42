/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:48:18 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/14 14:48:19 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_push_swap.h"

/* REVERSE ROTATE FUNCTIONS */

/* Puts the last element of A at the beginning of A */

void	ft_reverse_rotate_a_checker(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp_last;
	t_lst	*temp_second_last;

	temp = *stack;
	if (temp == NULL)
		return ;
	if (temp->next == NULL)
		return ;
	temp_last = ft_lstlast(*stack);
	temp_second_last = temp_last->previous;
	temp_second_last->next = NULL;
	temp_last->previous = NULL;
	temp_last->next = temp;
	temp->previous = temp_last;
	*stack = temp_last;
}
/* Puts the last element of B at the beginning of B */

void	ft_reverse_rotate_b_checker(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp_last;
	t_lst	*temp_second_last;

	temp = *stack;
	if (temp == NULL)
		return ;
	if (temp->next == NULL)
		return ;
	temp_last = ft_lstlast(*stack);
	temp_second_last = temp_last->previous;
	temp_second_last->next = NULL;
	temp_last->previous = NULL;
	temp_last->next = temp;
	temp->previous = temp_last;
	*stack = temp_last;
}

/* Does both RRA & RRB */

void	ft_reverse_rotate_a_and_b_checker(t_lst **stack_a, t_lst **stack_b)
{
	ft_reverse_rotate_a_checker(stack_a);
	ft_reverse_rotate_b_checker(stack_b);
}
