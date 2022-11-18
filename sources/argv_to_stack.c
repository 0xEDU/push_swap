/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:37:28 by etachott          #+#    #+#             */
/*   Updated: 2022/11/18 15:39:09 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	index;

	index = 1;
	while (stack)
	{
		ft_print("NODE %d: value = %d", index,
			stack->value);
		stack = stack->next;
		index++;
	}
}

t_stack	*create_empty_stack(int stack_size)
{
	t_stack	*stack;
	t_stack	*tail;
	int		index;

	index = stack_size - 1;
	tail = create_node(NULL);
	index--;
	while (index)
	{
		stack = create_node(NULL);
		add_node_front(&tail, stack);
		index--;
	}
	return (stack);
}

t_stack	*argv_to_stack(char *argv[], int stack_size)
{
	t_stack	*stack;
	t_stack	*tail;
	int		index;

	index = stack_size - 1;
	tail = create_node(argv[index--]);
	while (index)
	{
		stack = create_node(argv[index--]);
		add_node_front(&tail, stack);
	}
	return (tail);
}
