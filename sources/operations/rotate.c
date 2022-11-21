/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:34:18 by etachott          #+#    #+#             */
/*   Updated: 2022/11/21 15:07:15 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	tmp = (*stack)->next;
	head = *stack;
	head->next = NULL;
	*stack = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
}

void	rotate_a(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	tmp = (*stack)->next;
	head = *stack;
	head->next = NULL;
	*stack = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	ft_print("ra");
}

void	rotate_b(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	tmp = (*stack)->next;
	head = *stack;
	head->next = NULL;
	*stack = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	ft_print("rb");
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_print("rr");
}
