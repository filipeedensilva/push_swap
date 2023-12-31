/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:41:16 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/29 14:35:33 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int		sign;
	long	res;

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
	while (*str && *str == '0')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	skip_z(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	return (i);
}

void	check_num(char **values, t_node **a, long res, int j)
{
	int	i;

	i = skip_z(values[j]);
	res = ft_atol(values[j]);
	if (!is_num(values[j]) || !is_repeated(*a, res) || \
	res < INT_MIN || res > INT_MAX || (ft_strlen(values[j]) - i) > 10)
		error_msg(a, values);
	add_tail(a, add_node(res));
}

void	arg_check(int ac, char **av, t_node **a)
{
	static int	i;
	static int	j;
	long		res;
	char		**values;

	res = 0;
	if (ac >= 2)
	{
		while (av[++i])
		{
			values = ft_split(av[i], ' ');
			j = 0;
			while (values[j])
			{
				check_num(values, a, res, j);
				j++;
			}
			free_values(values);
		}
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}
