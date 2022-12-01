/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:31:16 by etachott          #+#    #+#             */
/*   Updated: 2022/12/01 02:29:08 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small(t_stack **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		swap_a(stack);
	else
		ft_print("");
}

void	sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size < 3)
		sort_small(stack_a);
	else if (stack_size == 3)
		sort_threes(stack_a);
	else
		sort_big(stack_a, stack_b, stack_size);
}
