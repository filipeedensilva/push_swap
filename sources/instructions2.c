/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:25:20 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/13 18:59:30 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ra(t_node **a)
{
	if (rotate(a) == 0)
		return (0);
	else 
		ft_printf("ra\n");
	return (1);
}

int	rb(t_node **b)
{
	if (rotate(b) == 0)
		return (0);
	else 
		ft_printf("rb\n");
	return (1);
}

int	rr(t_node **a, t_node **b)
{
	if (rotate(a) == 0 && rotate(b) == 0)
		return (0);
	else
		ft_printf("rr\n");
	return (1);
}

int	rra(t_node **a)
{
	if (!reverse_rotate(a))
		return (0);
	else
		ft_printf("rra\n");
	return (1);
}

int	rrb(t_node **b)
{
	if (!reverse_rotate(b))
		return (0);
	else
		ft_printf("rrb\n");
	return (1);
}

int	rrr(t_node **a, t_node **b)
{
	if (!reverse_rotate(a) && !reverse_rotate(b))
		return (0);
	else
		ft_printf("rra\n");
	return (1);
}
