/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:57:39 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/24 20:14:35 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_max_value(t_node *stack)
{
	int	max;
	t_node		*tmp;

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

t_node	*find_min_value(t_node *stack)
{
	long		smallest;
	t_node		*small;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			small = stack;
		}
		stack = stack->next;
	}
	return (small);
}

void	sort_3(t_node **a)
{
	t_node	*max;

	max = find_max_value(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_5(t_node **a, t_node **b)
{
	while (list_len(a) > 3)
	{
		if ((find_min_value(*a))->value == 0)
			pb(a, b);
		else
			ra(a);
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_all(t_node **a, t_node **b)
{
	int	average;
	int	bf;
	int	num;

	while (list_len(a) > 5)
	{
		average = get_average(a);
		if ((*a)->value < average)
			pb(a, b);
		else
		 	ra(a);
	}
	sort_5(a, b);
	while (*b)
	{
		bf = get_bf(a, (*b)->value);
		num = get_cheapest(*a, *b);
		climb_stack_a(a, num);
		climb_stack_b(b, bf);
		pa(a, b);
	}
	if (get_min_pos(a) > (list_len(a) / 2))
	{
		while ((*a)->value != find_min_value(*a)->value)
			rra(a);
	}
	else
		while ((*a)->value != find_min_value(*a)->value)
			ra(a);
}
