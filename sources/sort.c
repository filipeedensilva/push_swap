/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:55:29 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/24 20:22:50 by feden-pe         ###   ########.fr       */
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
