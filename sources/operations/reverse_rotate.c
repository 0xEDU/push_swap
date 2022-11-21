/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:05:12 by etachott          #+#    #+#             */
/*   Updated: 2022/11/21 15:09:51 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
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

void	reverse_rotate_a(t_stack **stack)
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
	ft_print("rra");
}

void	reverse_rotate_b(t_stack **stack)
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
	ft_print("rrb");
}

void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_print("rrr");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
