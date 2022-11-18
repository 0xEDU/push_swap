/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:05:12 by etachott          #+#    #+#             */
/*   Updated: 2022/11/18 17:41:41 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*tail;

	head = *stack;
	tmp = *stack;
	while (tmp->next)
	{
		tail = tmp;
		tmp = tmp->next;
	}
	tail->next = NULL;
	tmp->next = head;
	*stack = tmp;
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
