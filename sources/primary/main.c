/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:30 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 14:01:06 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	char	*result;

	if (argc != 1)
	{
		stack_a = NULL;
		stack_a = ft_first_stack_a(argc, argv, stack_a);
		stack_b = NULL;
		ft_look_for_doubles(&stack_a);
		result = ft_calloc(1000000, 1);
		if (!result)
			return (ft_free_stack(stack_a, result, NULL));
		if (argc < 15 || QUICK == 1)
			ft_easy_sort(argc, stack_a, stack_b, result);
		else
		{
			ft_algorithm(&stack_a, &stack_b, 10, result);
			ft_instructions(stack_b, result, argc, argv);
		}
		ft_putstr(result);
		stack_a = ft_tlststart(stack_a);
		ft_free_stack(stack_a, NULL, result);
	}
	return (0);
}

/* Looks for the shortest number of instructions to sort the stack */
/* We can change the basic parameters of the sorting functions */
/* Return Value = the string with the lowest numbers of instructions */

void	ft_instructions(t_lst *stack_b, char *result, int argc, char **argv)
{
	t_lst2	*l;

	l = malloc(sizeof(t_lst2));
	if (!l)
		return ;
	ft_set_loops_params(l, argc, argv);
	while (l->margin++ < l->max1)
	{
		l->i = l->i_value;
		while (l->i++ < l->i_max)
		{
			l->aloha = l->aloha_min;
			while (l->aloha++ < l->aloha_max)
			{
				l->w = 0;
				while (++l->w < 5)
				{
					ft_launch_a_try(l, stack_b, result);
				}
			}
		}
	}
	free(l);
}

/* The core of the loop function.*/

void	ft_launch_a_try(t_lst2 *l, t_lst *stack_b, char *result)
{
	t_lst	*stack_cpy;
	char	*re;

	stack_b = NULL;
	re = ft_calloc(1000000, 1);
	if (!re)
		return ;
	stack_cpy = ft_create_stack(l->argc, l->argv, l->margin, l->aloha);
	stack_cpy->increase = l->w;
	ft_algorithm(&stack_cpy, &stack_b, l->i, re);
	if (ft_count_n(result) >= ft_count_n(re))
		ft_strlcpy_ps(result, re, ft_strlen(re) + 2);
	ft_free_stack(stack_cpy, re, NULL);
}

/* Handles the small cases and the QUICK == 1 cases. */

void	ft_easy_sort(int argc, t_lst *stack_a, t_lst *stack_b, char *result)
{
	if (argc < 15)
		ft_lil_stack(stack_a, stack_b, argc, result);
	else if (QUICK == 1 && argc > 350)
		ft_algorithm(&stack_a, &stack_b, 15, result);
	else if (QUICK == 1)
		ft_algorithm(&stack_a, &stack_b, 6, result);
}

/* Handles the small cases */

void	ft_lil_stack(t_lst *stack_a, t_lst *stack_b, int argc, char *result)
{
	argc = ft_tlstsize(stack_a);
	if (argc == 3)
		ft_size_is_3(&stack_a, argc, result);
	else
		ft_algo_small(&stack_a, &stack_b, argc, result);
}
