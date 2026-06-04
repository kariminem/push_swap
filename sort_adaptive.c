/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:17:09 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/03 16:01:48 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_adaptive(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	double		disorder;
	int			len_list;

	disorder = calc_disorder(stack_a);
	len_list = ft_lstsize(stack_a->head);
	if (len_list == 2)
		ft_two_sort(stack_a, bench);
	else if (len_list == 3)
		ft_three_sort(stack_a, bench);
	else if (disorder < 0.2)
	{
		selection_sorting(stack_a, stack_b, bench);
		bench->strat = "simple";
	}
	else if (disorder >= 0.5)
	{
		ft_radix_sort(stack_a, stack_b, bench);
		bench->strat = "complex";
	}
	else
	{
		bucket_sorting(stack_a, stack_b, bench);
		bench->strat = "medium";
	}
}

void	ft_two_sort(t_stack *stack_a, t_bench *bench)
{
	if (*(int *)stack_a->tail->content < *(int *)stack_a->head->content)
		sa(stack_a, bench);
	return ;
}

void	ft_three_sort(t_stack *stack_a, t_bench *bench)
{
	if (is_sorted(stack_a->head))
		return ;
	else if (ft_max_pos_1(stack_a) == 1)
		ra(stack_a, bench);
	else if (*(int *)stack_a->tail->content > *(int *)stack_a->head->content)
		sa(stack_a, bench);
	else
		rra(stack_a, bench);
	ft_three_sort(stack_a, bench);
	return ;
}

int	ft_max_pos_1(t_stack *stack_a)
{
	int		max;
	t_list	*head;

	head = stack_a->head;
	max = *(int *)head->content;
	while (head != NULL)
	{
		if (max < *(int *)head->content)
			return (0);
		head = head->next;
	}
	return (1);
}
