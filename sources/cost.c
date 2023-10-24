/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:01:59 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/24 19:18:57 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_moves(t_node *stack, int num, int len)
{
	int	moves;
	int	middle;

	moves = 0;
	middle = len / 2;
	while (stack->value != num)
	{
		moves++;
		stack = stack->next;
	}
	if (moves > middle)
		return (len - moves);
	return (moves);
}

int	get_cost(t_node *a, t_node *b, int num, int bf)
{
	int	cost_a;
	int	cost_b;

	cost_a = get_moves(a, bf, list_len(&a));
	cost_b = get_moves(b, num, list_len(&b));
	return (cost_a + cost_b);
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
		cost = 	get_cost(a, b, tmp->value, bf);
		if (cost < cheapest)
		{
			num = tmp->value;
			cheapest = cost;
		}
		tmp = tmp->next;
	}
	return (num);
}
