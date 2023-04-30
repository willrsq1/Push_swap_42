/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:05:54 by wruet-su          #+#    #+#             */
/*   Updated: 2023/04/30 14:12:48 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h> /* for malloc */
# include <unistd.h> /* for write */
# include "ft_printf.h"
# include <stdint.h> /* for calloc */

# define QUICK 2 /* From 1 to 4 - Better results, longer calculations. */

typedef struct s_list
{
	int				content;
	int				position;
	int				order;
	int				increase;
	long			margin;
	double			aloha;
	struct s_list	*next;
	struct s_list	*previous;
}	t_lst;

typedef struct s_list2
{
	int				argc;
	char			**argv;
	int				w;
	int				margin;
	int				max1;
	int				i;
	int				i_value;
	int				i_max;
	int				aloha;
	int				aloha_min;
	int				aloha_max;
}	t_lst2;

/* -------------------------------------------------------------------------- */
/* Primary Sources ---------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* -------------------- All_Core_Functions.c -------------------------------- */

void	ft_algorithm(t_lst **stack_a, t_lst **stack_b, int i, char *r);
void	ft_first_sort(t_lst **stack_a, t_lst **stack_b, int i, char *r);
void	ft_second_sort(t_lst **stack_b, t_lst **stack_a, char *r);

/* -------------------- Loop_Values.c --------------------------------------- */

void	ft_set_loops_params(t_lst2 *l, int argc, char **argv);
void	ft_set_loops_params2(t_lst2 *l, int argc);
void	ft_set_loops_params3(t_lst2 *l);

/* -------------------- Main_Utils.c ---------------------------------------- */

t_lst	*ft_first_stack_a(int argc, char **argv, t_lst *stack_a);
void	ft_look_for_doubles(t_lst **stack);
int		ft_free_stack(t_lst *stack_a, char *re, char *result);

/* -------------------- Main.c ---------------------------------------------- */

int		main(int argc, char **argv);
void	ft_instructions(t_lst *stack_b, char *result, int argc, char **argv);
void	ft_launch_a_try(t_lst2 *l, t_lst *stack_b, char *result);
void	ft_easy_sort(int argc, t_lst *stack_a, t_lst *stack_b, char *result);
void	ft_lil_stack(t_lst *stack_a, t_lst *stack_b, int argc, char *result);

/* -------------------- Secondary_Utils.c ----------------------------------- */

void	ft_order(t_lst *lst, int size, t_lst **stack_a);
int		ft_find_new_max(int max, t_lst *lst);
int		ft_do_pa(t_lst **stack_a, t_lst **stack_b, char *r);
void	ft_final_push(t_lst *lst, t_lst *lst2, t_lst **stack_a, char *r);
int		ft_go_to_max_nb(t_lst **stack_a, t_lst **stack_b, char *r, int check);

/* -------------------- Utils_Of_First_Sort.c ------------------------------- */

int		ft_sort_in_b(t_lst **stack_b, int margin, char *r, int aloha);
void	ft_with_ra(t_lst **stack_a, t_lst **stack_b, int i, char *r);
int		ft_with_ra_part2(t_lst **stack_a, t_lst **stack_b, int i, char *r);
int		ft_increase_margin(int i, int margin, int w, int size);

/* -------------------- Utils_Of_Second_Sort.c ------------------------------ */

int		ft_handle_stocked(t_lst **stack_a, t_lst *lst, char *r, int check);
int		ft_stacking(t_lst **stack_a, t_lst **stack_b, char *r);
int		ft_find_direction_max(t_lst **stack_b);
int		ft_rota(int stocked, t_lst **stack_b, t_lst **stack_a, char *r);
int		ft_rev_rota(int stocked, t_lst **stack_b, t_lst **stack_a, char *r);

/* -------------------------------------------------------------------------- */
/* Secondary Sources -------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* -------------------- Libft_Functions.c ----------------------------------- */

int		ft_atoi_ps(const char *str, t_lst *lst);
void	ft_strlcpy_ps(char *dest, const char *src, size_t size);
int		ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/* -------------------- Lst_Utils.c ----------------------------------------- */

t_lst	*ft_create_stack(int argc, char **argv, int margin, int aloha);
t_lst	*ft_tlstnew(int content, t_lst *previous, int i, int margin);
int		ft_tlstsize(t_lst *lst);
t_lst	*ft_tlststart(t_lst *lst);
t_lst	*ft_lstlast(t_lst *lst);

/* -------------------- Push_Swap_Utils.c ----------------------------------- */

size_t	ft_count_n(char *r);
void	ft_stop_return(t_lst *stack);
int		ft_content_is_small(t_lst *lst);
int		ft_lst_is_sorted(t_lst *lst);

/* -------------------- Push.c ---------------------------------------------- */

void	ft_tlst_addfront(t_lst **stack_pushed, t_lst **stack);
void	ft_push_a(t_lst **stack_b, t_lst **stack_a, char *r);
void	ft_push_b(t_lst **stack_a, t_lst **stack_b, char *r);

/* -------------------- Reverse_Rotate.c ------------------------------------ */

void	ft_reverse_rotate_a(t_lst **stack, int a, char *r);
void	ft_rra(t_lst **stack);
void	ft_reverse_rotate_b(t_lst **stack, int a, char *r);
void	ft_rrb(t_lst **stack);
void	ft_reverse_rotate_a_and_b(t_lst **stack_a, t_lst **stack_b, char *r);

/* -------------------- Rotate.c -------------------------------------------- */

void	ft_rotate_a(t_lst **stack, int a, char *r);
void	ft_ra(t_lst **stack);
void	ft_rotate_b(t_lst **stack, int a, char *r);
void	ft_rb(t_lst **stack);
void	ft_rotate_a_and_b(t_lst **stack_a, t_lst **stack_b, char *r);

/* -------------------- Size_3_Stack_Algo.c --------------------------------- */

void	ft_size_is_3(t_lst **stack_a, int size, char *r);

/* -------------------- Small_Stacks_Algo.c --------------------------------- */

void	ft_algo_small(t_lst **stack_a, t_lst **stack_b, int size, char *r);
void	ft_just_go_for_min(t_lst **stack_a, t_lst **stack_b, int size, char *r);
int		ft_look_for_min(t_lst *lst);
void	ft_sort_small_with_ra(t_lst **stack_a, t_lst **stack_b, char *r);
void	ft_sort_small_rra(t_lst **stack_a, t_lst **stack_b, char *r);

/* -------------------- Swap.c ---------------------------------------------- */

void	ft_swap_a(t_lst **first, char *r);
void	ft_swap_b(t_lst **stack, char *r);
void	ft_swap_a_and_b(t_lst **stack_a, t_lst **stack_b, char *r);

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

#endif
