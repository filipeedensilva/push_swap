/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:34:19 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/13 17:47:55 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_node **a)
{
	if (swap(a) == 0)
		return (0);
	else
		ft_printf("sa\n");
	return (1);
}

int	sb(t_node **b)
{
	if (swap(b) == 0)
		return (0);
	else
		ft_printf("sb\n");
	return (1);
}

int	ss(t_node **a, t_node **b)
{
	if (swap(a) == 0 || swap(b) == 0)
		return (0);
	else
		ft_printf("ss\n");
	return (1);
}

int	pa(t_node **a, t_node **b)
{
	if (push(a, b) == 0)
		return (0);
	else
		ft_printf("pa\n");
	return (1);
}

int	pb(t_node **b, t_node **a)
{
	if (push(b, a) == 0)
		return (0);
	else
	 	ft_printf("pb\n");
	return (1);
}
