/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:13:22 by etachott          #+#    #+#             */
/*   Updated: 2022/12/08 15:06:55 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../../libft/includes/libft.h"

typedef struct s_stack {
	int				value;
	struct s_stack	*next;
}				t_stack;

void	add_node_back(t_stack **stack, t_stack *new);
void	add_node_front(t_stack **stack, t_stack *new);
void	apply_move_from_stdin(t_stack **stack_a, t_stack **stack_b);
t_stack	*argv_to_stack(char *argv[], int argc, int stack_size);
t_stack	*create_node(char *str);
void	ft_stackfree(t_stack **stack);
void	print_stack(t_stack *stack);
int		ft_matrixsize(char **matrix);
int		validate_input(char *argv[]);
int		validate_quotes(char *argv[]);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
void	super_swap(t_stack **stack_a, t_stack **stack_b);
#endif
