/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_threes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:19:20 by etachott          #+#    #+#             */
/*   Updated: 2022/11/21 17:37:34 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_if(t_stack **stack)
{
	if ((*stack)->index == 1
		&& (*stack)->next->index == 3
		&& (*stack)->next->next->index == 2)
		reverse_rotate_a(stack);
	if ((*stack)->index == 2
		&& (*stack)->next->index == 1
		&& (*stack)->next->next->index == 3)
		swap_a(stack);
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
}

void	sort_threes(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	big_if(stack);
}
