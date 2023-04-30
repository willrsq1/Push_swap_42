/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:58 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/11 16:47:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* UTILS FUNCTIONS */

size_t	ft_count_n(char *r)
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

/* Prints "Error" & exits the program */
/* Used the stop the program if the inputs are wrong */

void	ft_stop_return(t_lst *stack)
{
	if (stack != NULL)
		ft_free_stack(stack, NULL, NULL);
	write(2, "Error\n", 6);
	exit(0);
}

/* Checks if *lst is the lowest number of the stack */

int	ft_content_is_small(t_lst *lst)
{
	int	min;

	min = lst->content;
	if (!lst->next)
		return (1);
	while (lst)
	{
		if (lst->content < min)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/* Checks if the stack is sorted */
/* Returns 1 if it is */

int	ft_lst_is_sorted(t_lst *lst)
{
	int		temp;
	t_lst	*being_checked;

	while (lst)
	{
		being_checked = lst;
		temp = lst->content;
		while (lst->next)
		{
			lst = lst->next;
			if (lst->content < temp)
				return (0);
		}
		lst = being_checked->next;
	}
	return (1);
}
