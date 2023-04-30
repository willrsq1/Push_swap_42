/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:56:44 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/14 14:56:46 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_push_swap.h"

/* Mallocs and fills a new structure. */

t_lst	*ft_tlstnew(int content, t_lst *previous)
{
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (list == 0)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->previous = previous;
	return (list);
}

/* Returns the number of lists chained together. */

int	ft_tlstsize(t_lst *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* Returns the address of the first list of the chain. */

t_lst	*ft_tlststart(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->previous)
		lst = lst->previous;
	return (lst);
}

/* Goes to the last list of the chain. */

t_lst	*ft_lstlast(t_lst *lst)
{
	t_lst	*previous;

	previous = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		previous = lst;
		lst = lst->next;
	}
	return (previous);
}

/* Checks that the stack is ordered from smallest to highest content. */

int	ft_is_lst_sorted(t_lst **stack_a)
{
	t_lst	*lst;

	lst = *stack_a;
	lst = ft_tlststart(lst);
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
