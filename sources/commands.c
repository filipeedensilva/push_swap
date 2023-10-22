/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:03:24 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/13 18:46:05 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	
	if (!(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack = second;
	return (1);
}

int	push(t_node **stack, t_node **stack2)
{
	t_node	*top;

	if (!(*stack2))
		return (0);
	top = *stack2;
	*stack2 = (*stack2)->next;
	top->next = *stack;
	*stack = top;
	return (1);
}

int	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;
	
	if (!*stack || !(*stack)->next)
		return (0);
	tmp = (*stack)->next;
	last = find_tail(*stack);
	last->next = *stack;
	*stack = tmp;
	last->next->next = NULL;
	return (1);
}

int	reverse_rotate(t_node **stack)
{
	t_node	*current;
	t_node	*tail;

	if (!*stack || !(*stack)->next)
		return (0);
	current = *stack;
	tail = find_tail(*stack);
	while (current->next->next)
		current = current->next;
	tail->next = *stack;
	current->next = NULL;
	*stack = tail;
	return (1);
}
