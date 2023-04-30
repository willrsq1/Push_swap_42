/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:56:03 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/14 14:56:04 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_push_swap.h"

/* Creates a stack and checks its validity. */
/* Gets the instructions from input and executes them on the stack. */
/* Prints OK or KO zith the number of instructions used, and frees. */

int	main(int argc, char **argv)
{
	int		z;
	char	*line;
	char	*instructions;
	t_lst	*stack_a;
	t_lst	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_create_stack_checker(argc, argv);
	ft_look_for_doubles_checker(&stack_a);
	instructions = ft_calloc(420000, 1);
	line = ft_calloc(420000, 1);
	if (!line || !instructions)
		return (ft_free_checker(stack_a, stack_b, instructions, line), 0);
	argc = 0;
	while (read(0, line, 420000))
	{
		z = 0;
		while (line[z])
			instructions[argc++] = line[z++];
	}
	ft_print_result(instructions, line, &stack_a, &stack_b);
	ft_free_checker(stack_a, stack_b, instructions, line);
	return (0);
}

/* Prints OK if the stack is sorted and nothing is left in stack B. */
/* Prints KO if the stack isnt sorted. */
/* Prints KO if the stack is already sorted but instrucs are sent. */
/* Prints how many instructions were needed. */

void	ft_print_result(char *ins, char *line, t_lst **stack_a, t_lst **stack_b)
{
	int	nb_instr;
	int	size;

	if (ft_is_lst_sorted(stack_a) == 1 && ins[0] != '\0')
	{
		write(1, "KO\n", 3);
		return ;
	}
	ft_do_instructions(stack_a, stack_b, ins);
	if (*stack_a != NULL && ft_is_lst_sorted(stack_a) == 1 && *stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	nb_instr = ft_count_n_checker(ins);
	size = ft_tlstsize(ft_tlststart(*stack_a)) + ft_tlstsize(*stack_b);
	ft_printf("%d instructions, stack had %d numbers in it.\n", nb_instr, size);
	return ;
}

/* Counts the number of instructions used. */

size_t	ft_count_n_checker(char *r)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (r[i])
	{
		if (r[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

/* Creates the stack that will be used to check the instructions. */

t_lst	*ft_create_stack_checker(int argc, char **argv)
{
	int		i;
	t_lst	*stack_a;
	t_lst	*temp;

	i = 0;
	stack_a = NULL;
	stack_a = ft_tlstnew(ft_atoi_checker(argv[1], stack_a), NULL);
	while (i < argc - 2)
	{
		temp = ft_tlstnew(ft_atoi_checker(argv[i + 2], stack_a), stack_a);
		stack_a->next = temp;
		stack_a = stack_a->next;
		i++;
	}
	stack_a = ft_tlststart(stack_a);
	return (stack_a);
}
