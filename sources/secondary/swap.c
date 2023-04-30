/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:53 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/10 00:56:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* SWAP FUNCTIONS */

/* Swaps stack A's first 2 elements */

void	ft_swap_a(t_lst **stack, char *r)
{
	t_lst	*first;
	int		swap;
	int		i;

	first = *stack;
	if (first->next)
	{
		swap = first->content;
		first->content = first->next->content;
		first->next->content = swap;
		swap = first->order;
		first->order = first->next->order;
		first->next->order = swap;
		swap = first->position;
		first->position = first->next->position;
		first->next->position = swap;
		i = 0;
		while (r[i])
			i++;
		r[i] = 's';
		r[i + 1] = 'a';
		r[i + 2] = '\n';
	}
}

/* Swaps stack B's first 2 elements */

void	ft_swap_b(t_lst **stack, char *r)
{
	t_lst	*first;
	int		swap;
	int		i;

	first = *stack;
	if (first->next)
	{
		swap = first->content;
		first->content = first->next->content;
		first->next->content = swap;
		swap = first->order;
		first->order = first->next->order;
		first->next->order = swap;
		swap = first->position;
		first->position = first->next->position;
		first->next->position = swap;
		i = 0;
		while (r[i])
			i++;
		r[i] = 's';
		r[i + 1] = 'b';
		r[i + 2] = '\n';
	}
}

/* Does both SA & SB */

void	ft_swap_a_and_b(t_lst **stack_a, t_lst **stack_b, char *r)
{
	int	i;

	ft_swap_a(stack_a, r);
	ft_swap_b(stack_b, r);
	i = 0;
	while (r[i])
		i++;
	r[i] = 's';
	r[i + 1] = 's';
	r[i + 2] = '\n';
}
