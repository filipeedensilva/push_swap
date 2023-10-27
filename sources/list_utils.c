/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:51:35 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/27 16:40:47 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*add_node(long value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_node	*find_tail(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	add_tail(t_node **head, t_node *node)
{
	t_node	*tmp;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

int	list_len(t_node **stack)
{
	if (!*stack)
		return (0);
	else
		return (1 + list_len(&(*stack)->next));
}

void	print_list(t_node *head)
{
	int		i;
	t_node	*current;

	i = 0;
	current = head;
	while (current)
	{
		ft_printf("%d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}
