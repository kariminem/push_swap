/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:17:27 by username          #+#    #+#             */
/*   Updated: 2026/06/04 20:51:05 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}

int	error_exit(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(&(a->head), &free);
	ft_lstclear(&(b->head), &free);
	free(a);
	free(b);
	return (1);
}

void	cleanup(t_stack *a, t_stack *b)
{
	ft_lstclear(&(a->head), &free);
	ft_lstclear(&(b->head), &free);
	free(a);
	free(b);
}

void	print_stack(char *stack_name, t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->head;
	ft_printf("%s", stack_name);
	while (tmp)
	{
		ft_printf("%d --> ", *(int *) tmp->content);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}

void	run_strategy(char *strategy, t_bench *bench,
	t_stack	*stack_a, t_stack *stack_b)
{
	bench->disorder = calc_disorder(stack_a);
	if (ft_strncmp(strategy, "simple", 6) == 0)
		selection_sorting(stack_a, stack_b, bench);
	else if (ft_strncmp(strategy, "medium", 6) == 0)
		bucket_sorting(stack_a, stack_b, bench);
	else if (ft_strncmp(strategy, "complex", 7) == 0)
		merge_sort(stack_a, stack_b, bench);
	else
		ft_sort_adaptive(stack_a, stack_b, bench);
	if (bench->bench_active)
		bench_print(strategy, bench);
}
