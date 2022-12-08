/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:23:06 by etachott          #+#    #+#             */
/*   Updated: 2022/12/08 15:20:55 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	add_node_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	pop(t_stack **stack)
{
	t_stack	*prev_node;

	prev_node = *stack;
	*stack = (*stack)->next;
	free(prev_node);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = ft_calloc(sizeof(t_stack), 1);
	tmp->value = (*stack_b)->value;
	add_node_front(stack_a, tmp);
	pop(stack_b);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = ft_calloc(sizeof(t_stack), 1);
	tmp->value = (*stack_a)->value;
	add_node_front(stack_b, tmp);
	pop(stack_a);
}
