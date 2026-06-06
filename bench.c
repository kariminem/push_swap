/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:33:45 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/06 09:04:55 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_disorder(t_stack *stack_a)
{
	double	mistakes;
	double	total_pairs;
	t_list	*tmp;
	t_list	*tmp_outer;

	mistakes = 0;
	total_pairs = 0;
	if (is_sorted(stack_a->head))
		return (0);
	tmp_outer = stack_a->head;
	while (tmp_outer)
	{
		tmp = tmp_outer->next;
		while (tmp)
		{
			total_pairs += 1;
			if (*(int *)tmp_outer->content > *(int *)tmp->content)
				mistakes += 1;
			tmp = tmp->next;
		}
		tmp_outer = tmp_outer->next;
	}
	return (mistakes / total_pairs);
}

void	print_disorder(double disorder)
{
	int	percent;
	int	decimal;

	percent = (int)(disorder * 100);
	decimal = (int)(disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(percent, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd(" %\n", 2);
}

void	print_strat(char *strat, t_bench *bench)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(strat, 2);
	if (ft_strncmp(strat, "simple", 6) == 0)
		ft_putstr_fd(" / O(n\u00B2)\n", 2);
	else if (ft_strncmp(strat, "medium", 6) == 0)
		ft_putstr_fd(" / O(n\u221An)\n", 2);
	else if (ft_strncmp(strat, "complex", 7) == 0)
		ft_putstr_fd(" / O(nlog(n))\n", 2);
	else if (ft_strncmp(strat, "adaptive", 8) == 0)
	{
		if (bench->disorder < 0.2)
			ft_putstr_fd(" / O(n²)\n", 2);
		else if (bench->disorder < 0.5)
			ft_putstr_fd(" / O(n√n)\n", 2);
		else
			ft_putstr_fd(" / O(nlog(n))\n", 2);
	}
}

void	print_ops(t_bench *bench)
{
	ft_putnbr_fd(bench->total, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	bench_print(char *strat, t_bench *bench)
{
	print_disorder(bench->disorder);
	print_strat(strat, bench);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	print_ops(bench);
}
