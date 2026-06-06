/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:18:10 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/06 09:16:04 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_new_node(t_stack *list, int *ptr)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = ptr;
	new_node->next = NULL;
	if (!list->head)
		list->head = new_node;
	else
		list->tail->next = new_node;
	list->tail = new_node;
}

int	catch_duplicate(t_stack *list, int value)
{
	t_list	*current;

	current = list->head;
	while (current)
	{
		if (*(int *)current->content == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*strategy_parser(char **argv, t_bench *bench, int argc)
{
	char	*strat;
	int		i;

	strat = "adaptive";
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 8) == 0)
			strat = argv[i] + 2;
		else if (ft_strncmp(argv[i], "--show-ops=0", 12) == 0)
			bench -> show_ops = 0;
		else if (ft_strncmp(argv[i], "--medium", 8) == 0)
			strat = argv[i] + 2;
		else if (ft_strncmp(argv[i], "--complex", 9) == 0)
			strat = argv[i] + 2;
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			strat = argv[i] + 2;
		else if (ft_strncmp(argv[i], "--bench", 7) == 0)
			bench->bench_active = 1;
		else if (ft_strncmp(argv[i], "--", 2) == 0)
			return (NULL);
		i++;
	}
	return (strat);
}

int	parse_input(char **argv, int i, t_stack *a)
{
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			i++;
			continue ;
		}
		if (!process_number(argv[i], a))
			return (0);
		i++;
	}
	return (1);
}
