/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:00:51 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/14 15:00:52 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_push_swap.h"

/* Checks and executes the instructions one by one. */

void	ft_do_instructions(t_lst **stack_a, t_lst **stack_b, char *result)
{
	int		i;
	int		j;
	char	*instruction;

	i = 0;
	while (result[i])
	{
		j = 0;
		instruction = ft_calloc(100, 1);
		if (!instruction)
			return ;
		while (result && result[i] != '\n')
			instruction[j++] = result[i++];
		instruction[j] = result[i];
		i++;
		if (ft_check_arg(instruction) == 0)
			ft_stop_checker(*stack_a, *stack_b, result, instruction);
		ft_act_on_stack(instruction, stack_a, stack_b);
		if (instruction)
			free(instruction);
	}
}

/* Does the instructions corresponding to the instructions sent. */

void	ft_act_on_stack(char *instruction, t_lst **stack_a, t_lst **stack_b)
{
	if (instruction[0] == 's')
	{
		if (instruction[1] == 'a')
			ft_swap_a_checker(stack_a);
		else if (instruction[1] == 'b')
			ft_swap_b_checker(stack_b);
		else if (instruction[1] == 's')
			ft_swap_a_and_b_checker(stack_a, stack_b);
	}
	else if (instruction[0] == 'p')
	{
		if (instruction[1] == 'a')
			ft_push_a_checker(stack_b, stack_a);
		else if (instruction[1] == 'b')
			ft_push_b_checker(stack_a, stack_b);
	}
	else if (instruction[0] == 'r')
		ft_r_actions(instruction, stack_a, stack_b);
}

void	ft_r_actions(char *instruction, t_lst **stack_a, t_lst **stack_b)
{
	if (instruction[1] == 'a')
		ft_rotate_a_checker(stack_a);
	else if (instruction[1] == 'b')
		ft_rotate_b_checker(stack_b);
	else if (instruction[1] == 'r')
	{
		if (instruction[2] == '\n')
			ft_rotate_a_and_b_checker(stack_a, stack_b);
		else if (instruction[2] == 'a')
			ft_reverse_rotate_a_checker(stack_a);
		else if (instruction[2] == 'b')
			ft_reverse_rotate_b_checker(stack_b);
		else if (instruction[2] == 'r')
			ft_reverse_rotate_a_and_b_checker(stack_a, stack_b);
	}
}
