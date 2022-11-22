/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:21:40 by etachott          #+#    #+#             */
/*   Updated: 2022/11/22 11:06:59 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	head = (*stack_a)->next->next;
	ft_print("PUSH_TO_B HEAD = %d", head->value);
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

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	push_to_b(stack_a, stack_b);
}
