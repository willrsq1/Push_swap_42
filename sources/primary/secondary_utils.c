/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 00:19:45 by root              #+#    #+#             */
/*   Updated: 2022/12/11 01:58:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Sets the order in which the lists will need to be sorted */

void	ft_order(t_lst *lst, int size, t_lst **stack_a)
{
	int	min;
	int	order;

	order = 1;
	size = ft_tlstsize(*stack_a);
	while (order < size + 1 && lst)
	{
		lst = ft_tlststart(*stack_a);
		min = 2147483647;
		while (lst)
		{
			if (lst->content < min && lst->order < 0)
				min = lst->content;
			lst = lst->next;
		}
		lst = ft_tlststart(*stack_a);
		while (lst->content != min)
			lst = lst->next;
		lst->order = order;
		order = order + 1;
	}
}

/* Gets the order of the top value in the stack */

int	ft_find_new_max(int max, t_lst *lst)
{
	while (lst)
	{
		if (lst->order >= max)
			max = lst->order;
		lst = lst->next;
	}
	return (max);
}

/* Pushes the max - 1 elem from B to A and sets the check to 1. */
/* By setting the check to 1, the elem will be swapped back to its place. */

int	ft_do_pa(t_lst **stack_a, t_lst **stack_b, char *r)
{
	ft_push_a(stack_b, stack_a, r);
	return (1);
}

/* Pushes any remaining values in B to A. */

void	ft_final_push(t_lst *lst, t_lst *lst2, t_lst **stack_a, char *r)
{
	lst = *stack_a;
	lst2 = ft_lstlast(*stack_a);
	while (lst->content > lst2->content)
	{
		ft_reverse_rotate_a(stack_a, 0, r);
		lst = *stack_a;
		lst2 = ft_lstlast(*stack_a);
	}
}

/* Either goes to the max nb with rb or rrb. */
/* Goes to the max number with the shortest way possible. */
/* Check is the order of numbers pushed and ra'ed until needed. */

int	ft_go_to_max_nb(t_lst **stack_a, t_lst **stack_b, char *r, int check)
{
	int		pos;

	pos = ft_find_direction_max(stack_b);
	if (pos == -1)
		check = ft_rev_rota(check, stack_b, stack_a, r);
	else
		check = ft_rota(check, stack_b, stack_a, r);
	return (check);
}
