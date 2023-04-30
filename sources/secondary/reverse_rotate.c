/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:58:38 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/10 00:55:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* REVERSE ROTATE FUNCTIONS */

/* Puts the last element of A at the beginning of A */

void	ft_reverse_rotate_a(t_lst **stack, int a, char *r)
{
	t_lst	*temp;
	int		i;

	temp = *stack;
	if (temp->next == NULL)
		return ;
	ft_rra(stack);
	if (a == 0)
	{
		i = 0;
		while (r[i])
			i++;
		if (i > 10 && r[i - 2] == 'r' && r[i - 3] == 'r' && r[i - 4] == 'r' \
			&& r[i - 6] == 'b' && r[i - 7] == 'r' && r[i - 8] == 'r')
			r[i - 6] = 'r';
		else if (i > 5 && r[i - 2] == 'b' && r[i - 3] == 'r' && r[i - 4] == 'r')
			r[i - 2] = 'r';
		else
		{
			r[i] = 'r';
			r[i + 1] = 'r';
			r[i + 2] = 'a';
			r[i + 3] = '\n';
		}
	}
}

void	ft_rra(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp_last;
	t_lst	*temp_second_last;

	temp = *stack;
	temp_last = ft_lstlast(*stack);
	temp_second_last = temp_last->previous;
	temp_second_last->next = NULL;
	temp_last->previous = NULL;
	temp_last->next = temp;
	temp->previous = temp_last;
	*stack = temp_last;
}
/* Puts the last element of B at the beginning of B */

void	ft_reverse_rotate_b(t_lst **stack, int a, char *r)
{
	t_lst	*temp;
	int		i;

	temp = *stack;
	if (temp->next == NULL)
		return ;
	ft_rrb(stack);
	if (a == 0)
	{
		i = 0;
		while (r[i])
			i++;
		if (i > 10 && r[i - 2] == 'r' && r[i - 3] == 'r' && r[i - 4] == 'r' \
			&& r[i - 6] == 'a' && r[i - 7] == 'r' && r[i - 8] == 'r')
			r[i - 6] = 'r';
		else if (i > 5 && r[i - 2] == 'a' && r[i - 3] == 'r' && r[i - 4] == 'r')
			r[i - 2] = 'r';
		else
		{	
			r[i] = 'r';
			r[i + 1] = 'r';
			r[i + 2] = 'b';
			r[i + 3] = '\n';
		}
	}
}

void	ft_rrb(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp_last;
	t_lst	*temp_second_last;

	temp = *stack;
	temp_last = ft_lstlast(*stack);
	temp_second_last = temp_last->previous;
	temp_second_last->next = NULL;
	temp_last->previous = NULL;
	temp_last->next = temp;
	temp->previous = temp_last;
	*stack = temp_last;
}

/* Does both RRA & RRB */

void	ft_reverse_rotate_a_and_b(t_lst **stack_a, t_lst **stack_b, char *r)
{
	int	i;

	ft_reverse_rotate_a(stack_a, 1, r);
	ft_reverse_rotate_b(stack_b, 1, r);
	i = 0;
	while (r[i])
		i++;
	r[i] = 'r';
	r[i + 1] = 'r';
	r[i + 2] = 'r';
	r[i + 3] = '\n';
}
