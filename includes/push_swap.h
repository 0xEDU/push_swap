/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:26:11 by etachott          #+#    #+#             */
/*   Updated: 2022/11/17 16:19:01 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

typedef struct s_stack {
	int				value;
//	int				index;
//	int				pos;
//	int				target_pos;
//	int				cost_a;
//	int				cost_b;
	struct s_stack	*next;
}				t_stack;

t_stack	*argv_to_stack(char *argv[], int stack_size);
t_stack	*create_node(char *str);
t_stack	*create_empty_stack(int stack_size);
void	ft_stackfree(t_stack **stack);
void	print_stack(t_stack *stack);
void	super_swap(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
int		validate_input(char *argv[]);
#endif
