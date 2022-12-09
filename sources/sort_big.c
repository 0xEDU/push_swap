/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:21:40 by etachott          #+#    #+#             */
/*   Updated: 2022/12/09 17:49:30 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	index;
	int	sent;
	int	stack_mid;

	index = 0;
	sent = 0;
	stack_mid = stack_size / 2;
	while (stack_size > 6 && index < stack_size && sent < stack_mid)
	{
		if ((*stack_a)->index <= stack_mid)
		{
			push_b(stack_a, stack_b);
			sent++;
		}
		else
			rotate_a(stack_a);
		index++;
	}
	while (stack_size - sent > 3)
	{
		push_b(stack_a, stack_b);
		sent++;
	}
}

void	get_current_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		index;

	index = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = index;
		tmp = tmp->next;
		index++;
	}
}

/*	push_to_b(stack_a, stack_b);
 *	sort_threes(stack_a);
 *	while (has_value(stack_b))
 *	{
 *		find_current_pos(stack_b); // Find current position of all elements
 *		calculate_target_pos(stack_a, stack_b); // Calc target pos in stack_a
 *		calculate_move_cost(stack_a, stack_b); // Calc cost for
 *		execute_actions(stack_a, stack_b);
 *	}
 *	if (!is_sorted(stack_a))
 *		#decide if ra or rra
 */

void	sort_big(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	push_to_b(stack_a, stack_b, stack_size);
	sort_threes(stack_a);
	while (*stack_b)
	{
		get_current_pos(stack_a);
		get_current_pos(stack_b);
		calculate_target_pos(stack_a, stack_b);
		calculate_move_cost(stack_a, stack_b);
		executioner(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		arrange_stack(stack_a);
}
