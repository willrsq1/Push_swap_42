/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:38:37 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/10 00:56:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_algo_small(t_lst **stack_a, t_lst **stack_b, int size, char *r)
{
	t_lst	*lst;

	lst = *stack_a;
	ft_order(lst, size, stack_a);
	while (ft_lst_is_sorted(lst) == 0 && lst->next)
	{
		if (ft_content_is_small(lst))
			ft_push_b(stack_a, stack_b, r);
		else
			ft_just_go_for_min(stack_a, stack_b, size, r);
		lst = ft_tlststart(*stack_a);
	}
	lst = *stack_b;
	while (lst)
	{
		ft_push_a(stack_b, stack_a, r);
		lst = *stack_b;
	}
}

/* Sorts by sending the lowest value */

void	ft_just_go_for_min(t_lst **stack_a, t_lst **stack_b, int size, char *r)
{
	t_lst	*lst;
	int		pos;

	lst = *stack_a;
	if (size > 0)
	size = ft_tlstsize(lst);
	pos = ft_look_for_min(lst);
	if (pos < size / 2)
		ft_sort_small_with_ra(stack_a, stack_b, r);
	else
		ft_sort_small_rra(stack_a, stack_b, r);
}

/* Finds the min and returns its positions in the stack */
/* Allows us to know the mmost efficient way to get to it - ra or rra */

int	ft_look_for_min(t_lst *lst)
{
	int	content;
	int	position;
	int	min_pos;

	content = lst->content;
	lst->position = 0;
	lst = lst->next;
	position = 0;
	while (lst)
	{
		lst->position = position;
		position = position + 1;
		if (lst->content < content)
		{
			content = lst->content;
			min_pos = lst->position;
		}
		lst = lst->next;
	}
	return (min_pos);
}

/* Sorts with rotate a */

void	ft_sort_small_with_ra(t_lst **stack_a, t_lst **stack_b, char *r)
{
	t_lst	*lst;

	lst = *stack_a;
	if (ft_content_is_small(lst))
		ft_push_b(stack_a, stack_b, r);
	else if (ft_content_is_small(lst->next))
	{
		ft_swap_a(stack_a, r);
		if (ft_lst_is_sorted(lst) == 0)
			ft_push_b(stack_a, stack_b, r);
	}
	else
		ft_rotate_a(stack_a, 0, r);
}

/* Sorts with reverse rotate a */

void	ft_sort_small_rra(t_lst **stack_a, t_lst **stack_b, char *r)
{
	t_lst	*lst;

	lst = *stack_a;
	if (ft_content_is_small(lst))
		ft_push_b(stack_a, stack_b, r);
	else if (ft_content_is_small(lst->next))
	{
		ft_swap_a(stack_a, r);
		if (ft_lst_is_sorted(lst) == 0)
			ft_push_b(stack_a, stack_b, r);
	}
	else
		ft_reverse_rotate_a(stack_a, 0, r);
}
