/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:37:28 by etachott          #+#    #+#             */
/*   Updated: 2022/12/09 17:33:15 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	index;

	index = 1;
	if (!stack)
		ft_print("STACK IS NULL.");
	while (stack)
	{
		ft_print("NODE %d: vl = %d idx = %d ps = %d trg = %d ca = %d cb = %d",
			index,
			stack->value,
			stack->index,
			stack->pos,
			stack->target_pos,
			stack->cost_a,
			stack->cost_b);
		stack = stack->next;
		index++;
	}
}

int	ft_matrixsize(char **matrix)
{
	int	index;

	index = 0;
	while (matrix[index])
		index++;
	return (index);
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

t_stack	*quotes_treatment(char *argv[])
{
	t_stack	*head;
	t_stack	*stack;
	char	**word_matrix;
	int		index;

	word_matrix = ft_split(argv[1], ' ');
	index = 0;
	if ((ft_matrixsize(word_matrix) - 1) == 1)
	{
		free(word_matrix);
		return (NULL);
	}
	head = create_node(word_matrix[index++]);
	while (index < ft_matrixsize(word_matrix) - 1)
	{
		stack = create_node(word_matrix[index++]);
		add_node_back(&head, stack);
	}
	ft_freematrix(word_matrix);
	return (head);
}

t_stack	*argv_to_stack(char *argv[], int argc, int stack_size)
{
	t_stack	*stack;
	t_stack	*head;
	int		index;

	head = NULL;
	index = 1;
	if (argc != 2)
	{
		head = create_node(argv[index++]);
		while (index < stack_size)
		{
			stack = create_node(argv[index++]);
			add_node_back(&head, stack);
		}
	}
	else
		head = quotes_treatment(argv);
	return (head);
}
