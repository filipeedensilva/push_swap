/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:04:02 by feden-pe          #+#    #+#             */
/*   Updated: 2023/10/24 20:33:41 by feden-pe         ###   ########.fr       */
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

void	error_msg(char *str, t_node **stack);
void	free_values(char **values);
int	swap(t_node **stack);
int	push(t_node **stack, t_node **stack2);
int	rotate(t_node **stack);
int	reverse_rotate(t_node **stack);
void	free_stack(t_node **stack);

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

//sorting algorithms
void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);
void	sort_all(t_node **a, t_node **b);

// checks
int	is_sorted(t_node *stack);
void	arg_check(int ac, char **av, t_node **head);
void	sort(t_node **a, t_node **b);

// list utils
void	add_tail(t_node **head, t_node *node);
t_node	*add_node(long value);
t_node	*find_tail(t_node *head);

// sort util
int	get_average(t_node **stack);
int	list_len(t_node **stack);
int	get_bf(t_node **stack, int num);
t_node	*find_min_value(t_node *stack);
int	get_min_pos(t_node **stack);

int	get_cheapest(t_node *a, t_node *b);
void	climb_stack_a(t_node **a, int num);
void	climb_stack_b(t_node **b, int num);

#endif
