/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:34:18 by etachott          #+#    #+#             */
/*   Updated: 2022/12/08 15:18:00 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	tmp = (*stack)->next;
	head = *stack;
	head->next = NULL;
	*stack = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
