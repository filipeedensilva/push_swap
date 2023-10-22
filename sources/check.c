/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:41:16 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/13 19:18:12 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_num(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_repeated(t_node *head, int num)
{
	while (head)
	{
		if (num == head->value)
			return (0);
		head = head->next;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	arg_check(char **av, t_node **head)
{
	static int	i;
	static int	j;
	long		res;
	char		**values;

	while (av[++i])
	{
		values = ft_split(av[i], ' ');
		while (values[j])
		{
			res = ft_atol(values[j]);
			if (!is_num(values[j]))
				error_msg("arg is not a number!", values, *head);
			if (!is_repeated(*head, res))
				error_msg("number is repeated!", values, *head);
			if (res < INT_MIN || res > INT_MAX)
				error_msg("number is not in the interger scope!", values, *head);
			add_tail(head, add_node(res));
			j++;
		}
		free_values(values);
		j = 0;
	}
}
