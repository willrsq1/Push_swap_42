/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:48:09 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/14 14:48:11 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_push_swap.h"

/* ROTATE FUNCTIONS */

/* Puts the first element of A at the end of A */

void	ft_rotate_a_checker(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp_last;
	t_lst	*temp_start;

	temp = *stack;
	if (temp == NULL)
		return ;
	if (temp->next == NULL)
		return ;
	temp_start = temp->next;
	temp_last = ft_lstlast(*stack);
	temp_start->previous = NULL;
	temp->next = NULL;
	temp->previous = temp_last;
	temp_last->next = temp;
	*stack = temp_start;
}

/* Puts the first element of B at the end of B */

void	ft_rotate_b_checker(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp_last;
	t_lst	*temp_start;

	temp = *stack;
	if (temp == NULL)
		return ;
	if (temp->next == NULL)
		return ;
	temp_start = temp->next;
	temp_last = ft_lstlast(*stack);
	temp_start->previous = NULL;
	temp->next = NULL;
	temp->previous = temp_last;
	temp_last->next = temp;
	*stack = temp_start;
}

/* Does both RA & RB */

void	ft_rotate_a_and_b_checker(t_lst **stack_a, t_lst **stack_b)
{
	ft_rotate_a_checker(stack_a);
	ft_rotate_b_checker(stack_b);
}
