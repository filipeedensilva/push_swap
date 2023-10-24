/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:19:05 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/24 19:34:29 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	climb_stack_a(t_node **a, int num)
{
	t_node	*tmp;
	int		count;
	int		len;

	count = 0;
	tmp = *a;
	len = list_len(a);
	while (tmp && tmp->value != num)
	{
		count++;
		tmp = tmp->next;
	}
	if (count > (len / 2))
	{
		count = len - count;
		while (count-- > 0)
			rra(a);
	}
	else
	{
		while (count-- > 0)
			ra(a);
	}

}

void	climb_stack_b(t_node **b, int num)
{
	t_node	*tmp;
	int		count;
	int		len;

	count = 0;
	tmp = *b;
	len = list_len(b);
	while (tmp && tmp->value != num)
	{
		count++;
		tmp = tmp->next;
	}
	if (count > (len / 2))
	{
		count = len - count;
		while (count-- > 0)
			rrb(b);
	}
	else
	{
		while (count-- > 0)
			rb(b);
	}

}
