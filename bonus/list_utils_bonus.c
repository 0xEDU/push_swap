/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:28:39 by etachott          #+#    #+#             */
/*   Updated: 2022/12/08 14:47:46 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
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

void	add_node_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = new;
}
