/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:48:58 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/27 16:49:48 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrr(t_node **a, t_node **b)
{
	if (!reverse_rotate(a) && !reverse_rotate(b))
		return (0);
	else
		ft_printf("rra\n");
	return (1);
}
