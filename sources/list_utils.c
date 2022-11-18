/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:28:39 by etachott          #+#    #+#             */
/*   Updated: 2022/11/18 15:28:34 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackfree(t_stack **stack)
{
	t_stack	*prev_node;

	prev_node = *stack;
	while (*stack && prev_node)
	{
		prev_node = *stack;
		*stack = (*stack)->next;
		free(prev_node);
	}
	*stack = NULL;
}

void	pop(t_stack **stack)
{
	t_stack	*prev_node;

	prev_node = *stack;
	*stack = (*stack)->next;
	free(prev_node);
}

t_stack	*create_node(char *str)
{
	t_stack	*node;

	node = ft_calloc(sizeof (t_stack), 1);
	if (str)
		node->value = ft_atoi(str);
	node->next = NULL;
	return (node);
}

void	add_node_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}
