/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:35 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/11 17:21:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* PUSH FUNCTIONS */

/* Pushes the first elem of a stack to the beginning of the other */
/* Removes it from the first */

void	ft_tlst_addfront(t_lst **stack_pushed, t_lst **stack)
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

void	ft_push_a(t_lst **stack_b, t_lst **stack_a, char *r)
{
	int	i;

	if (*stack_b)
	{
		ft_tlst_addfront(stack_b, stack_a);
		i = 0;
		while (r[i])
			i++;
		r[i] = 'p';
		r[i + 1] = 'a';
		r[i + 2] = '\n';
	}
}

/* Pushes the 1st element of A on top of B */

void	ft_push_b(t_lst **stack_a, t_lst **stack_b, char *r)
{
	int	i;

	if (*stack_a)
	{
		ft_tlst_addfront(stack_a, stack_b);
		i = 0;
		while (r[i])
			i++;
		r[i] = 'p';
		r[i + 1] = 'b';
		r[i + 2] = '\n';
	}
}
