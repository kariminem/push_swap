/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:03:12 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/03 15:52:25 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorter(char *operation, t_stack *stack_a, t_stack *stack_b,
			t_bench *bench);

void	read_ops(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		ft_sorter(line, stack_a, stack_b, bench);
		free(line);
		line = get_next_line(0);
	}
}

void	ft_sorter(char *operation, t_stack *stack_a, t_stack *stack_b,
			t_bench *bench)
{
	if ((ft_strncmp(operation, "sa", 2)) == 0)
		sa(stack_a, bench);
	else if ((ft_strncmp(operation, "sb", 2)) == 0)
		sb(stack_b, bench);
	else if ((ft_strncmp(operation, "ss", 2)) == 0)
		ss(stack_a, stack_b, bench);
	else if ((ft_strncmp(operation, "ra", 2)) == 0)
		ra(stack_a, bench);
	else if ((ft_strncmp(operation, "rb", 2)) == 0)
		rb(stack_b, bench);
	else if ((ft_strncmp(operation, "rr", 3)) == 0)
		rr(stack_a, stack_b, bench);
	else if ((ft_strncmp(operation, "pa", 2)) == 0)
		pa(stack_a, stack_b, bench);
	else if ((ft_strncmp(operation, "pb", 2)) == 0)
		pb(stack_a, stack_b, bench);
	else if ((ft_strncmp(operation, "rra", 3)) == 0)
		rra(stack_a, bench);
	else if ((ft_strncmp(operation, "rrb", 3)) == 0)
		rrb(stack_b, bench);
	else if ((ft_strncmp(operation, "rrr", 3)) == 0)
		rrr(stack_a, stack_b, bench);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	ft_memset(bench, 0, sizeof(t_bench));
	bench->show_ops = 0;
	bench->bench_active = 0;
	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!parse_input(argv, 1, stack_a))
		return (error_exit(stack_a, stack_b));
	read_ops(stack_a, stack_b, bench);
	if (is_sorted(stack_a->head) && !(stack_b->head))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	cleanup(stack_a, stack_b);
	return (0);
}
