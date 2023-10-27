/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:17:48 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/27 16:43:57 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_average(t_node **stack)
{
	int		count;
	long	sum;
	t_node	*tmp;

	tmp = NULL;
	sum = 0;
	count = 0;
	tmp = (*stack);
	while (tmp)
	{
		sum += tmp->value;
		count++;
		tmp = tmp->next;
	}
	return (sum / count);
}

int	get_bf(t_node **stack, int num)
{
	t_node	*tmp;
	int		bf;

	tmp = *stack;
	bf = INT_MAX;
	while (tmp)
	{
		if (bf > tmp->value && tmp->value > num)
			bf = tmp->value;
		tmp = tmp->next;
	}
	return (bf);
}

int	get_min_pos(t_node **stack)
{
	t_node	*tmp;
	int		min;
	int		i;

	tmp = *stack;
	i = 0;
	min = find_min_value(*stack);
	while (tmp->value != min)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
