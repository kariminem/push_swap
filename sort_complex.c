/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbliard <gbliard@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:02:00 by gbliard           #+#    #+#             */
/*   Updated: 2026/06/03 15:05:50 by gbliard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max_binary(t_list *head)
{
	int	i;
	int	value;
	int	max;

	max = 0;
	while (head != NULL)
	{
		i = 0;
		value = *(int *)head->content;
		while (value > 0)
		{
			value = value >> 1;
			i++;
		}
		max = ft_max(i, max);
		head = head ->next;
	}
	return (max);
}

void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	int	pos;
	int	n;
	int	current_byte;

	pos = 0;
	current_byte = 0;
	n = ft_lstsize(stack_a->head);
	while (!is_sorted(stack_a->head))
	{
		if (!ft_skip_pass(stack_a, current_byte))
		{
			while (pos < n)
			{
				if (((*(int *)stack_a->head->content >> current_byte) & 1) == 1)
					ra(stack_a, bench);
				else
					pb(stack_a, stack_b, bench);
				pos++;
			}
			while (stack_b->head != NULL)
				pa(stack_a, stack_b, bench);
		}
		pos = 0;
		current_byte++;
	}
}

int	ft_skip_pass(t_stack *stack_a, int current_byte)
{
	t_list	*ptr;
	int		byte_1;

	ptr = stack_a->head;
	byte_1 = ((*(int *)ptr ->content >> current_byte) & 1);
	while (ptr != NULL)
	{
		if (((*(int *)ptr ->content >> current_byte) & 1) != byte_1)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
