/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:59:26 by wruet-su          #+#    #+#             */
/*   Updated: 2022/12/14 14:59:28 by wruet-su         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PUSH_SWAP_H
# define CHECKER_PUSH_SWAP_H
# include <stdlib.h> /* for malloc */
# include <unistd.h> /* for write */
# include <stdint.h> /* for calloc bzero */
# include <sys/types.h> /* for open*/
# include <sys/stat.h> /* for open*/
# include <fcntl.h> /* for open*/
# include "../../../includes/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
}	t_lst;

/* -------------------- Do_Instructions.c ----------------------------------- */

void	ft_do_instructions(t_lst **stack_a, t_lst **stack_b, char *result);
void	ft_act_on_stack(char *instruction, t_lst **stack_a, t_lst **stack_b);
void	ft_r_actions(char *instruction, t_lst **stack_a, t_lst **stack_b);

/* -------------------- Libft_Functions_Checker.c --------------------------- */

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/* -------------------- Lst_Utils_Checker.c --------------------------------- */

t_lst	*ft_tlstnew(int content, t_lst *previous);
int		ft_tlstsize(t_lst *lst);
t_lst	*ft_tlststart(t_lst *lst);
t_lst	*ft_lstlast(t_lst *lst);
int		ft_is_lst_sorted(t_lst **stack_a);

/* -------------------- Main_Functions.c ------------------------------------ */

int		ft_atoi_checker(char *str, t_lst *lst);
void	ft_stop_checker(t_lst *stack, t_lst *stack_b, char *result, char *s);
int		ft_free_checker(t_lst *stack_a, t_lst *stack_b, char *re, char *result);
int		ft_check_arg(char *s);
void	ft_look_for_doubles_checker(t_lst **stack);

/* -------------------- Main.c ---------------------------------------------- */

int		main(int argc, char **argv);
void	ft_print_result(char *ins, char *line, t_lst **stack, t_lst **stack_b);
size_t	ft_count_n_checker(char *r);
t_lst	*ft_create_stack_checker(int argc, char **argv);

/* -------------------- Push_Checker.c -------------------------------------- */

void	ft_tlst_addfront_checker(t_lst **stack_pushed, t_lst **stack);
void	ft_push_a_checker(t_lst **stack_b, t_lst **stack_a);
void	ft_push_b_checker(t_lst **stack_a, t_lst **stack_b);

/* -------------------- Reverse_Rotate_Checker.c ---------------------------- */

void	ft_reverse_rotate_a_checker(t_lst **stack);
void	ft_reverse_rotate_b_checker(t_lst **stack);
void	ft_reverse_rotate_a_and_b_checker(t_lst **stack_a, t_lst **stack_b);

/* -------------------- Rotate_Checker.c ------------------------------------ */

void	ft_rotate_a_checker(t_lst **stack);
void	ft_rotate_b_checker(t_lst **stack);
void	ft_rotate_a_and_b_checker(t_lst **stack_a, t_lst **stack_b);

/* -------------------- Swap_Checker.c -------------------------------------- */

void	ft_swap_a_checker(t_lst **stack);
void	ft_swap_b_checker(t_lst **stack);
void	ft_swap_a_and_b_checker(t_lst **stack_a, t_lst **stack_b);

/* -------------------------------------------------------------------------- */

#endif
