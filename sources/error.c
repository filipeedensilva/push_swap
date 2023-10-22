/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:24:15 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/22 19:56:37 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->value = 0;
		free(*stack);
		(*stack) = tmp;
	}
}

void	error_msg(char *str, char **values, t_node **stack)
{
	if (str)
		ft_printf("Error: %s\n", str);
	free_stack(stack);
	exit(0 );
}
