/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:25 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/11 13:52:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* LST UTILS */

/* Creates stack A, a chain list */

t_lst	*ft_create_stack(int argc, char **argv, int margin, int aloha)
{
	int		i;
	t_lst	*stack_a;
	t_lst	*temp;

	i = 0;
	stack_a = NULL;
	stack_a = ft_tlstnew(ft_atoi_ps(argv[1], stack_a), NULL, i, margin);
	stack_a->aloha = aloha;
	while (i < argc - 2)
	{
		temp = ft_tlstnew(ft_atoi_ps(argv[i + 2], stack_a), stack_a, i, margin);
		stack_a->next = temp;
		stack_a->aloha = aloha;
		stack_a = stack_a->next;
		i++;
	}
	stack_a = ft_tlststart(stack_a);
	return (stack_a);
}

/* Creates each list, containing each number to be sorted */

t_lst	*ft_tlstnew(int content, t_lst *previous, int i, int margin)
{
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (list == 0)
		return (NULL);
	list->content = content;
	list->position = i;
	list->order = -1;
	list->increase = 2;
	list->margin = margin;
	list->next = NULL;
	list->previous = previous;
	return (list);
}

/* Returns the number of lists chained together */

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

/* Returns the address of the first list of the chain */

t_lst	*ft_tlststart(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->previous)
		lst = lst->previous;
	return (lst);
}

/* Goes to the last list of the chain */

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
