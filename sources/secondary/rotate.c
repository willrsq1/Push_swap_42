/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:58:30 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/10 00:56:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* ROTATE FUNCTIONS */

/* Puts the first element of A at the end of A */

void	ft_rotate_a(t_lst **stack, int a, char *r)
{
	t_lst	*temp;
	int		i;

	temp = *stack;
	if (temp->next == NULL)
		return ;
	ft_ra(stack);
	if (a == 0)
	{
		i = 0;
		while (r[i])
			i++;
		r[i] = 'r';
		r[i + 1] = 'a';
		r[i + 2] = '\n';
	}
}

void	ft_ra(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp_last;
	t_lst	*temp_start;

	temp = *stack;
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

void	ft_rotate_b(t_lst **stack, int a, char *r)
{
	t_lst	*temp;
	int		i;

	temp = *stack;
	if (temp->next == NULL)
		return ;
	ft_rb(stack);
	if (a == 0)
	{
		i = 0;
		while (r[i])
			i++;
		r[i] = 'r';
		r[i + 1] = 'b';
		r[i + 2] = '\n';
	}
}

void	ft_rb(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp_last;
	t_lst	*temp_start;

	temp = *stack;
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

void	ft_rotate_a_and_b(t_lst **stack_a, t_lst **stack_b, char *r)
{
	int	i;

	ft_rotate_a(stack_a, 1, r);
	ft_rotate_b(stack_b, 1, r);
	i = 0;
	while (r[i])
		i++;
	r[i] = 'r';
	r[i + 1] = 'r';
	r[i + 2] = '\n';
}
