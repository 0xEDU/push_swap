/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_threes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:19:20 by etachott          #+#    #+#             */
/*   Updated: 2022/11/22 10:17:09 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	big_if(t_stack **stack)
{
	if ((*stack)->index < (*stack)->next->index
		&& (*stack)->index < (*stack)->next->next->index)
		reverse_rotate_a(stack);
	if ((*stack)->index > (*stack)->next->index
		&& (*stack)->index < (*stack)->next->next->index)
		swap_a(stack);
	if ((*stack)->index < (*stack)->next->index
		&& (*stack)->index > (*stack)->next->next->index)
		reverse_rotate_a(stack);
	if ((*stack)->index > (*stack)->next->index
		&& (*stack)->index > (*stack)->next->next->index
		&& (*stack)->next->index < (*stack)->next->next->index)
		rotate_a(stack);
	if ((*stack)->index > (*stack)->next->index
		&& (*stack)->next->index > (*stack)->next->next->index)
	{
		rotate_a(stack);
		swap_a(stack);
	}
}

void	sort_threes(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	big_if(stack);
}
