/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:01:59 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/27 16:40:06 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_moves(t_node *stack, int num, int len)
{
	int	moves;

	moves = 0;
	while (stack->value != num)
	{
		moves++;
		stack = stack->next;
	}
	if (moves > (len / 2))
		return (len - moves);
	return (moves);
}

int	get_cost(t_node *a, t_node *b, int num, int bf)
{
	static int	cost;

	cost = get_moves(a, bf, list_len(&a));
	cost += get_moves(b, num, list_len(&b));
	return (cost);
}

int	get_cheapest(t_node *a, t_node *b)
{
	t_node	*tmp;
	int		num;
	int		bf;
	int		cost;
	int		cheapest;

	tmp = b;
	num = b->value;
	cheapest = INT_MAX;
	while (tmp)
	{
		bf = get_bf(&a, tmp->value);
		cost = get_cost(a, b, tmp->value, bf);
		if (cost < cheapest)
		{
			num = tmp->value;
			cheapest = cost;
		}
		tmp = tmp->next;
	}
	return (num);
}

t_node	*find_max_value(t_node *stack)
{
	int		max;
	t_node	*tmp;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			tmp = stack;
		}
		stack = stack->next;
	}
	return (tmp);
}

int	find_min_value(t_node *stack)
{
	int		min;
	t_node	*tmp;

	tmp = stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
		}
		tmp = tmp->next;
	}
	return (min);
}
