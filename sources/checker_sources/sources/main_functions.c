/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:53:56 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/14 14:53:57 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_push_swap.h"

/* Atoi functions that checks that the args are numbers. */

int	ft_atoi_checker(char *str, t_lst *stack_a)
{
	unsigned long long	result;
	int					sign;
	int					i;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - 48);
	if (i == 0 || (i == 1 && (str[0] == '-' || str[0] == '+')))
		ft_stop_checker(stack_a, NULL, NULL, NULL);
	if ((result >= 2147483648 && sign == 1) || str[i] != '\0')
		ft_stop_checker(stack_a, NULL, NULL, NULL);
	if (result > 2147483648 && sign == -1)
		ft_stop_checker(stack_a, NULL, NULL, NULL);
	return (result * sign);
}

/* Frees and exits when then inputs are wrong. */

void	ft_stop_checker(t_lst *stack, t_lst *stack_b, char *result, char *s)
{
	stack = ft_tlststart(stack);
	ft_free_checker(stack, stack_b, result, s);
	write(2, "Error\n", 6);
	exit(0);
}

/* Frees structs and strings. */

int	ft_free_checker(t_lst *stack_a, t_lst *stack_b, char *re, char *result)
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
	if (stack_b != NULL)
		ft_free_checker(stack_b, NULL, NULL, NULL);
	if (re != NULL)
		free(re);
	if (result != NULL)
		free(result);
	return (0);
}

/* Check that the instructions are valid. */
/* Allows the end of entry caracter for manual entry of instructions. (ascii 3) */

int	ft_check_arg(char *s)
{
	if ((s[0] == 's' && s[1] == 'a' && s[2] == '\n' && s[3] == '\0') || \
		(s[0] == 's' && s[1] == 'b' && s[2] == '\n' && s[3] == '\0') || \
		(s[0] == 's' && s[1] == 's' && s[2] == '\n' && s[3] == '\0') || \
		(s[0] == 'p' && s[1] == 'a' && s[2] == '\n' && s[3] == '\0') || \
		(s[0] == 'p' && s[1] == 'b' && s[2] == '\n' && s[3] == '\0') || \
		(s[0] == 'r' && s[1] == 'a' && s[2] == '\n' && s[3] == '\0') || \
		(s[0] == 'r' && s[1] == 'b' && s[2] == '\n' && s[3] == '\0') || \
		(s[0] == 'r' && s[1] == 'r' && s[2] == '\n' && s[3] == '\0') || \
		(s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n' && \
		s[4] == '\0') || (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && \
		s[3] == '\n' && s[4] == '\0') || (s[0] == 'r' && s[1] == 'r' && \
		s[2] == 'r' && s[3] == '\n' && s[4] == '\0'))
	{
		return (1);
	}
	else if (s[0] == 3)
		return (1);
	else
		return (0);
}

/* Checks for doubles and stops if there is any */

void	ft_look_for_doubles_checker(t_lst **stack)
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
				ft_stop_checker(*stack, NULL, NULL, NULL);
			dpl = dpl->next;
		}
		temp = temp->next;
	}
	*stack = start;
}
