/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:17:48 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/22 18:32:06 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	list_len(t_node **stack)
{
	if (!*stack)
		return (0);
	else
	 	return (1 + list_len(&(*stack)->next));
}

int	get_average(t_node **stack)
{
	int		sum;
	int		count;
	t_node	*tmp;

	sum = 0;
	count = list_len(stack);
	tmp = (*stack);
	while (tmp)
	{
		sum += tmp->value;
		tmp = tmp->next;
	}
	return (sum / count);
}
