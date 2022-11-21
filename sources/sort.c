/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:31:16 by etachott          #+#    #+#             */
/*   Updated: 2022/11/21 15:17:48 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_threes_one(t_stack **stack)
{
	if ((*stack)->index == 1
		&& (*stack)->next->index == 2
		&& (*stack)->next->next->index == 3)
		ft_print("");
	if ((*stack)->index == 1
		&& (*stack)->next->index == 3
		&& (*stack)->next->next->index == 2)
		reverse_rotate_a(stack);
	if ((*stack)->index == 2
		&& (*stack)->next->index == 1
		&& (*stack)->next->next->index == 3)
		swap_a(stack);
	else
		return ;
}

void	sort_threes_two(t_stack **stack)
{
	if ((*stack)->index == 2
		&& (*stack)->next->index == 3
		&& (*stack)->next->next->index == 1)
		reverse_rotate_a(stack);
	if ((*stack)->index == 3
		&& (*stack)->next->index == 1
		&& (*stack)->next->next->index == 2)
		rotate_a(stack);
	if ((*stack)->index == 3
		&& (*stack)->next->index == 2
		&& (*stack)->next->next->index == 1)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else
		return ;
}

void	sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	(void)stack_b;
	ft_print("STACK SIZE = %d", stack_size);
	if (stack_size < 3)
		ft_print("sort_small(stack_a);");
	else if (stack_size == 3)
	{
		sort_threes_one(stack_a);
		sort_threes_two(stack_a);
	}
	else
		ft_print("sort_big(stack_a, stack_b);");
}
