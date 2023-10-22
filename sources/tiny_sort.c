/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:57:39 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/22 19:56:25 by feden-pe         ###   ########.fr       */
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

void	tiny_sort(t_node **a)
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
	tiny_sort(a);
	pa(a, b);
	pa(a, b);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
