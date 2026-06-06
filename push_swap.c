/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:17:53 by username          #+#    #+#             */
/*   Updated: 2026/06/06 09:00:33 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_all(t_stack **a, t_stack **b, t_bench **bench)
{
	*bench = malloc(sizeof(t_bench));
	if (!*bench)
		return (0);
	ft_memset(*bench, 0, sizeof(t_bench));
	(*bench)->show_ops = 1;
	*a = init_stack();
	*b = init_stack();
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_bench	*bench_stack;
	char	*strategy;

	if (argc < 2)
		return (0);
	if (!init_all(&stack_a, &stack_b, &bench_stack))
		return (1);
	strategy = strategy_parser(argv, bench_stack, argc);
	if (!strategy || !parse_input(argv, 1, stack_a))
	{
		free(bench_stack);
		return (error_exit(stack_a, stack_b));
	}
	if (!stack_a->head)
	{
		free(bench_stack);
		cleanup(stack_a, stack_b);
		return (0);
	}
	run_strategy(strategy, bench_stack, stack_a, stack_b);
	cleanup(stack_a, stack_b);
	free(bench_stack);
	return (0);
}
