/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:43:03 by root              #+#    #+#             */
/*   Updated: 2022/12/12 23:08:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Creates the initial stack. */

t_lst	*ft_first_stack_a(int argc, char **argv, t_lst *stack_a)
{
	if (argc > 350)
		stack_a = ft_create_stack(argc, argv, 70, 15);
	else
		stack_a = ft_create_stack(argc, argv, 31, 8);
	return (stack_a);
}

/* Checks for doubles and stops if there is any */

void	ft_look_for_doubles(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*dpl;
	t_lst	*start;

	temp = *stack;
	start = temp;
	while (temp)
	{
		dpl = temp->next;
		while (dpl)
		{
			if (dpl->content == temp->content)
				ft_stop_return(*stack);
			dpl = dpl->next;
		}
		temp = temp->next;
	}
	if (ft_lst_is_sorted(*stack) == 1)
	{
		ft_free_stack(*stack, NULL, NULL);
		exit(0);
	}
	*stack = start;
}

/* Frees stacks and strings */

int	ft_free_stack(t_lst *stack_a, char *re, char *result)
{
	t_lst	*temp;

	if (stack_a != NULL)
	{
		stack_a = ft_tlststart(stack_a);
		while (stack_a->next)
		{
			temp = stack_a->next;
			free(stack_a);
			stack_a = temp;
		}
		free(stack_a);
	}
	if (re != NULL)
		free (re);
	if (result != NULL)
		free (result);
	return (0);
}
