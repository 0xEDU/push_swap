/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:05:12 by etachott          #+#    #+#             */
/*   Updated: 2022/12/08 15:24:15 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*tail;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
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

void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
