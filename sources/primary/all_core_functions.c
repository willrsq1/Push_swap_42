/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_core_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:01 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/11 15:11:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* -------------------------------------------------------------------------- */
/* ---------------------------- FT_ALGORITHM ---------------------------------*/
/* -------------------------------------------------------------------------- */
/* The alogirthm's function. ------------------------------------------------ */
/* ft_order sorts the numbers from 1 to 'size' of the stack. ---------------- */
/* ft_first_sort will take value from stack A to stack B. ------------------- */
/* ft_second_sort will put the values back from B to A. --------------------- */
/* ----------------------The stack is now sorted ! -------------------------- */
/* -------------------------------------------------------------------------- */

void	ft_algorithm(t_lst **stack_a, t_lst **stack_b, int i, char *r)
{
	t_lst	*lst;
	int		size;

	lst = *stack_a;
	size = ft_tlstsize(*stack_a);
	ft_order(lst, size, stack_a);
	lst = *stack_a;
	ft_first_sort(stack_a, stack_b, i, r);
	ft_second_sort(stack_b, stack_a, r);
}

/* -------------------------------------------------------------------------- */
/* ----------------------------- FT_FIRST_SORT -------------------------------*/
/* -------------------------------------------------------------------------- */
/* Function that handles all the initial sorting from stack_a to stack_b. --- */
/* It sorts with a margin of error - It pushes the lowest numbers first. ---- */
/* -------------------------------------------------------------------------- */
/* ft_with_ra will rotate through the stack until a push happens. ----------- */
/* The value to be pushed will be selected thanks to the variable margin. --- */
/* Margin increases in value everytime a number is pushed to stack_b. ------- */
/* This happens thanks to the ft_increase_margin function. ------------------ */
/* -------------------------------------------------------------------------- */
/* The value pushed will be sorted arriving in stack_b with either SB or RB.  */
/* This will happen thanks to the function ft_sort_in_b. -------------------- */
/* It returns 1 if a RB if needed, so that it happens as RR in the next loop. */
/* -------------------------------------------------------------------------- */
/* ------------- When stack_a is emptied, the function stops. --------------- */
/* -------------------------------------------------------------------------- */

void	ft_first_sort(t_lst **stack_a, t_lst **stack_b, int i, char *r)
{
	int		size;
	t_lst	*lst;
	int		hello;
	int		margin;
	int		w;

	lst = *stack_a;
	hello = 0;
	w = lst->increase;
	margin = lst->margin;
	while (lst)
	{
		size = ft_tlstsize(lst);
		while (lst)
		{
			lst->margin = margin;
			lst = lst->next;
		}
		lst = ft_tlststart(*stack_a);
		ft_with_ra(stack_a, stack_b, hello, r);
		margin = ft_increase_margin(i, margin, w, size);
		hello = ft_sort_in_b(stack_b, margin, r, lst->aloha);
		lst = ft_tlststart(*stack_a);
		i++;
	}
}

/* -------------------------------------------------------------------------- */
/* ---------------------------- FT_SECOND_SORT -------------------------------*/
/* This function will put back all of stack B in stack A. ------------------- */
/* While doing so, it will sort it perfectly, for A to be ordered. ---------- */
/* -------------------------------------------------------------------------- */
/* If the check is positive, some values are stashed at the end of stack A.   */
/* This means that these values need to be RRA'd back on top of A. ---------- */
/* It will happen if the value stocked is the one immediately smaller to the  */
/* ---- one that is at the top of A at the time. ---------------------------- */
/* The values will be checked and ordered in ft_handle_stocked. ------------- */
/* -------------------------------------------------------------------------- */
/* ft_go_to_max_nb goes to the max value with RB or RRB and returns positive  */
/*		check == 1 if along the way some numbers go stocked in stack A. ----- */
/* -------------------------------------------------------------------------- */
/* If any number remains in B it will be pushed to A with ft_final_push. ---- */
/* ----------------- Now the stack is sorted and back in A ! ---------------- */
/* -------------------------------------------------------------------------- */

void	ft_second_sort(t_lst **stack_b, t_lst **stack_a, char *r)
{
	t_lst	*lst;
	t_lst	*lst2;
	int		check;

	lst = *stack_b;
	lst2 = NULL;
	check = 0;
	while (lst)
	{
		if (check > 0)
			check = ft_handle_stocked(stack_a, lst, r, check);
		check = ft_go_to_max_nb(stack_a, stack_b, r, check);
		lst = ft_tlststart(*stack_b);
	}
	ft_final_push(lst, lst2, stack_a, r);
}
