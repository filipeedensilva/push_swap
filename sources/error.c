/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:24:15 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/28 21:33:11 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_values(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
			free(args[i++]);
		free(args);
	}
}

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

void	error_msg(t_node **stack, char **args)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack);
	if (args)
		free_values(args);
	exit(0);
}
