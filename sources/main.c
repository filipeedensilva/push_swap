/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:02:22 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/29 14:36:52 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;

	a = NULL;
	b = NULL;
	arg_check(ac, av, &a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	sort(&a, &b);
	free_stack(&a);
}
