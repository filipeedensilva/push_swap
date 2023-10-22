/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:04:02 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/22 19:33:18 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int		value;
	struct s_node	*next;
}		t_node;

void	arg_check(char **av, t_node **head);
void	add_tail(t_node **head, t_node *node);
t_node	*find_tail(t_node *head);
t_node	*add_node(long value);
void	error_msg(char *str, char **values, t_node **stack);
void	free_values(char **values);
void	print_list(t_node *head);
int	list_len(t_node **stack);
int	swap(t_node **stack);
int	push(t_node **stack, t_node **stack2);
int	rotate(t_node **stack);
int	reverse_rotate(t_node **stack);

// operations
int	sa(t_node **a);
int	sb(t_node **b);
int	ss(t_node **a, t_node **b);
int	pa(t_node **a, t_node **b);
int	pb(t_node **b, t_node **a);
int	ra(t_node **a);
int	rb(t_node **b);
int	rr(t_node **a, t_node **b);
int	rra(t_node **a);
int	rrb(t_node **b);
int	rrr(t_node **a, t_node **b);

#endif
