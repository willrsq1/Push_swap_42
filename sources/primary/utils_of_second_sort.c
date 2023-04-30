/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_of_second_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:09 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/10 23:04:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* ALGORITHM PART 2 */

int	ft_handle_stocked(t_lst **stack_a, t_lst *lst, char *r, int check)
{
	t_lst	*lst2;
	int		stacked_order;

	stacked_order = check;
	lst = *stack_a;
	lst2 = ft_lstlast(*stack_a);
	if (lst2->order < lst->order)
	{
		lst2 = ft_lstlast(*stack_a);
		while (lst2->order == lst->order - 1)
		{
			ft_reverse_rotate_a(stack_a, 0, r);
			lst = *stack_a;
			lst2 = ft_lstlast(*stack_a);
		}
		stacked_order = lst2->order;
		if (lst2->order > lst->order && ft_tlstsize(*stack_a) > 3)
			stacked_order = 0;
		return (stacked_order);
	}
	return (stacked_order);
}

/* */

int	ft_stacking(t_lst **stack_a, t_lst **stack_b, char *r)
{
	int		max;
	t_lst	*lst;

	lst = ft_tlststart(*stack_b);
	max = -1;
	max = ft_find_new_max(max, lst);
	ft_push_a(stack_b, stack_a, r);
	if (ft_find_direction_max(stack_b) == -1)
	{
		ft_rotate_a(stack_a, 0, r);
		max = -1;
	}
	else if (lst->next && lst->next->order != max - 1)
		ft_rotate_a_and_b(stack_a, stack_b, r);
	else
		ft_rotate_a(stack_a, 0, r);
	return (max);
}

/* Returns -1 or 1 to algorithm_part2 */
/* Decides if we will go get the max value of stack B with rb or rra */

int	ft_find_direction_max(t_lst **stack_b)
{
	t_lst	*lst;
	t_lst	*end;
	int		max;

	lst = *stack_b;
	end = ft_lstlast(*stack_b);
	max = -2147483648;
	while (lst)
	{
		if (lst->order >= max)
			max = lst->order;
		lst = lst->next;
	}
	lst = *stack_b;
	while (lst && end)
	{
		if (lst->order == max)
			return (1);
		if (end->order == max)
			return (-1);
		lst = lst->next;
		end = end->previous;
	}
	return (0);
}

/* Goes to the value to be sent to Stack A while using rotate_b */

int	ft_rota(int stocked, t_lst **stack_b, t_lst **stack_a, char *r)
{
	int		max;
	int		check;
	t_lst	*lst;

	check = 0;
	lst = *stack_b;
	max = -1;
	max = ft_find_new_max(max, lst);
	while (lst && lst->order < max)
	{
		if (lst->order == max - 1)
			check = ft_do_pa(stack_a, stack_b, r);
		else if (lst->order >= stocked && lst->next->order < max)
		{
			max = ft_stacking(stack_a, stack_b, r);
			stocked = lst->order;
		}
		else
			ft_rotate_b(stack_b, 0, r);
		lst = ft_tlststart(*stack_b);
	}
	ft_push_a(stack_b, stack_a, r);
	if (check == 1)
		ft_swap_a(stack_a, r);
	return (stocked);
}

/* Goes to the value to be sent to Stack A while using reverse_rotate_b */

int	ft_rev_rota(int stocked, t_lst **stack_b, t_lst **stack_a, char *r)
{
	int		max;
	t_lst	*lst;
	t_lst	*end;

	lst = *stack_b;
	end = ft_lstlast(*stack_b);
	max = -1;
	max = ft_find_new_max(max, lst);
	while (lst->order < max)
	{
		if (end->previous && lst->order >= stocked && \
			end->order < max && end->previous->order < max)
		{
			stocked = lst->order;
			ft_push_a(stack_b, stack_a, r);
			ft_rotate_a(stack_a, 0, r);
			if (ft_find_direction_max(stack_b) == 1)
				return (stocked);
		}
		else
			ft_reverse_rotate_b(stack_b, 0, r);
		lst = ft_tlststart(*stack_b);
	}
	ft_push_a(stack_b, stack_a, r);
	return (stocked);
}
