/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:41:16 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/27 18:50:45 by feden-pe         ###   ########.fr       */
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

void	check_num(char **values, t_node **a, long res, int j)
{
	char	*check;

	res = ft_atol(values[j]);
	check = ft_itoa(res);
	if (!is_num(values[j]))
		error_msg(a, values);
	if (!is_repeated(*a, res))
		error_msg(a, values);
	if (res < INT_MIN || res > INT_MAX || (ft_strlen(check) > 11))
	{
		free(check);
		error_msg(a, values);
	}
	add_tail(a, add_node(res));
	free(check);
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
		ft_printf("Error\n");
		exit(0);
	}
}
