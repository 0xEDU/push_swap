/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:26:11 by etachott          #+#    #+#             */
/*   Updated: 2022/11/24 18:05:35 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# include "../libft/includes/libft.h"

typedef struct s_stack {
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}				t_stack;

t_stack	*argv_to_stack(char *argv[], int stack_size);
void	add_node_front(t_stack **stack, t_stack *new);
void	calculate_move_cost(t_stack **stack_a, t_stack **stack_b);
void	calculate_target_pos(t_stack **stack_a, t_stack **stack_b);
t_stack	*create_node(char *str);
t_stack	*create_empty_stack(int stack_size);
void	ft_stackfree(t_stack **stack);
int		has_value(t_stack *stack);
void	init_index(t_stack **stack);
int		is_sorted(t_stack *head);
void	print_stack(t_stack *stack);
void	pop(t_stack **stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack);
void	reverse_rotate_b(t_stack **stack);
void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	super_swap(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b, int stack_size);
void	sort_big(t_stack **stack_a, t_stack **stack_b, int stack_size);
void	sort_threes(t_stack **stack);
int		validate_input(char *argv[]);
#endif
