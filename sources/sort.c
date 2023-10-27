/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:55:29 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/27 16:35:24 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_node **a, t_node **b)
{
	int	len;

	len = list_len(a);
	if (len <= 3)
		sort_3(a);
	else if (len <= 5)
		sort_5(a, b);
	else
		sort_all(a, b);
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
		if ((get_min_pos(a)) == 0)
			pb(b, a);
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

	while (list_len(a) > 5)
	{
		average = get_average(a);
		if ((*a)->value < average)
			pb(b, a);
		else
			ra(a);
	}
	sort_5(a, b);
	push_swap(a, b);
}

void	push_swap(t_node **a, t_node **b)
{
	int	bf;
	int	num;

	while (*b)
	{
		num = get_cheapest(*a, *b);
		bf = get_bf(a, num);
		climb_stack_b(b, num);
		climb_stack_a(a, bf);
		pa(a, b);
	}
	if (get_min_pos(a) > (list_len(a) / 2))
	{
		while ((*a)->value != find_min_value(*a))
			rra(a);
	}
	else
		while ((*a)->value != find_min_value(*a))
			ra(a);
}
