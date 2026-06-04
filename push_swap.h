/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbliard <gbliard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:26:44 by username          #+#    #+#             */
/*   Updated: 2026/06/03 15:20:46 by gbliard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct t_stack
{
	t_list	*head;
	t_list	*tail;
}	t_stack;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	int		show_ops;
	int		bench_active;
	double	disorder;
	char	*strat;
}	t_bench;

/**
* Swap the first two elements at the top of stack a
*/
void	sa(t_stack *stack, t_bench *bench);
/**
* Swap the first two elements at the top of stack b
*/
void	sb(t_stack *stack, t_bench *bench);
/**
* Swap the first two elements at the top of stack a and b
*/
void	ss(t_stack *a, t_stack *b, t_bench *bench);
/**
* Take the first element at the top of a and put it at the top of b
*/
void	pb(t_stack *a, t_stack *b, t_bench *bench);
/**
* Take the first element at the top of b and put it at the top of a
*/
void	pa(t_stack *a, t_stack *b, t_bench *bench);
/**
* Shift down all elements of stack a by one
*/
void	rra(t_stack *stack, t_bench *bench);
/**
* Shift down all elements of stack b by one, last -> first
*/
void	rrb(t_stack *stack, t_bench *bench);
/**
* Shift down all elements of stack a and b by one, last -> first
*/
void	rrr(t_stack *a, t_stack *b, t_bench *bench);
/**
*  Shift up all elements of stack a by one
*/
void	ra(t_stack *stack, t_bench *bench);
/**
*  Shift up all elements of stack b by one, first -> last
*/
void	rb(t_stack *stack, t_bench *bench);
/**
*  Shift up all elements of stack a and b by one, first -> last
*/
void	rr(t_stack *a, t_stack *b, t_bench *bench);
void	print_stack(char *stack_name, t_stack *stack);
void	sort_simple(t_stack *a, t_stack *b);
t_stack	*init_stack(void);
int		error_exit(t_stack *a, t_stack *b);
int		process_number(char *arg, t_stack *a);
void	cleanup(t_stack *a, t_stack *b);
int		parse_input(char **argv, int i, t_stack *a);
void	run_strategy(char *strategy, t_bench *bench,
			t_stack	*stack_a, t_stack *stack_b);
char	*strategy_parser(char **argv, t_bench *bench, int argc);
void	selection_sorting(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
long	ft_atol(const char *str);
void	ft_new_node(t_stack *list, int *ptr);
int		catch_duplicate(t_stack *list, int value);
int		is_valid_int(char *str);

int		find_min(t_list *lst);
void	bucket_sorting(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
void	bench_print(char *strat, t_bench *bench);
int		is_sorted(t_list *lst);
double	calc_disorder(t_stack *stack_a);
int		ft_compute_disorder(t_stack *stack_a);
int		find_max_pos(t_list *lst, int max_num);
void	ft_sort_adaptive(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
void	ft_three_sort(t_stack *stack_a, t_bench *bench);
void	ft_two_sort(t_stack *stack_a, t_bench *bench);
int		ft_max_pos_1(t_stack *stack_a);
int		ft_skip_pass(t_stack *stack_a, int current_byte);
void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
int		ft_find_max_binary(t_list *head);
int		ft_max(int a, int b);
#endif
