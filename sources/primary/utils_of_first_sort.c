/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_of_first_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:05:43 by wruet-su          #+#    #+#             */
/*   Updated: 2023/01/22 15:01:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* 2 FUNCTIONS FOR BIG STACKS - 3 FUNCTIONS TO SORT REGULAR SIZED STACKS*/

/* Sorts values upon arrival in B.*/
/* Sorts them in a half-hourglass shape. */

int	ft_sort_in_b(t_lst **stack_b, int margin, char *r, int aloha)
{
	t_lst	*lst;
	t_lst	*end;
	int		hello;

	hello = 0;
	lst = ft_tlststart(*stack_b);
	end = lst;
	while (end && end->next)
		end = end->next;
	if (lst && lst->next && lst->next->next)
	{
		if (lst->order < margin - aloha || lst->order == end->order - 1 || \
			lst->order == end->order + 1)
			hello = 1;
		else if (lst->order < lst->next->order)
			ft_swap_b(stack_b, r);
	}
	return (hello);
}

/* Rotates until any of the conditions are met. */
/* Gets to the values we want to push to B. */

void	ft_with_ra(t_lst **stack_a, t_lst **stack_b, int i, char *r)
{
	t_lst	*lst;
	int		check;
	int		margin;

	lst = *stack_a;
	margin = lst->margin;
	check = margin * ft_tlstsize(*stack_a) / 20;
	while (check > 0)
	{
		if (lst->order <= margin + lst->aloha && i == 0)
		{
			ft_push_b(stack_a, stack_b, r);
			return ;
		}
		else if (lst->order <= margin + lst->aloha && i == 1)
		{
			ft_rotate_b(stack_b, 0, r);
			ft_push_b(stack_a, stack_b, r);
			return ;
		}
		else
			i = ft_with_ra_part2(stack_a, stack_b, i, r);
		lst = ft_tlststart(*stack_a);
		check = check - 3;
	}
}

/* Second Part */
/* Does rr instead of rb + ra or ra is nothing happens*/

int	ft_with_ra_part2(t_lst **stack_a, t_lst **stack_b, int i, char *r)
{
	if (i == 1)
	{
		ft_rotate_a_and_b(stack_a, stack_b, r);
		i = 0;
	}
	else
		ft_rotate_a(stack_a, 0, r);
	return (i);
}

/* This function increases the margin when a value is pushed to B */

int	ft_increase_margin(int i, int margin, int w, int size)
{
	if (i > margin - 2)
	{
		if (margin < size)
			return (margin + 1 + w);
		else
			return (margin + w);
	}
	return (margin);
}
