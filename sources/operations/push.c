/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:23:06 by etachott          #+#    #+#             */
/*   Updated: 2022/12/01 02:25:07 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = ft_calloc(sizeof(t_stack), 1);
	tmp->value = (*stack_b)->value;
	tmp->index = (*stack_b)->index;
	add_node_front(stack_a, tmp);
	pop(stack_b);
	ft_print("pa");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = ft_calloc(sizeof(t_stack), 1);
	tmp->value = (*stack_a)->value;
	tmp->index = (*stack_a)->index;
	add_node_front(stack_b, tmp);
	pop(stack_a);
	ft_print("pb");
}
