/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:02:26 by etachott          #+#    #+#             */
/*   Updated: 2022/12/01 00:44:57 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_actions(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	if (cost->a > 0 && cost->b > 0)
		exec_rotate_rotate(stack_a, stack_b, cost);
	else if (cost->a < 0 && cost->b < 0)
		exec_reverse_rotate_rotate(stack_a, stack_b, cost);
	exec_a(stack_a, cost);
	exec_b(stack_b, cost);
	push_a(stack_a, stack_b);
}

void	executioner(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_cost	cost;
	int		best_move;
	int		candidate;

	tmp = *stack_b;
	cost.a = tmp->cost_a;
	cost.b = tmp->cost_b;
	best_move = ft_abs(cost.a) + ft_abs(cost.b);
	tmp = tmp->next;
	while (tmp)
	{
		candidate = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		if (candidate < best_move)
		{
			best_move = candidate;
			cost.a = tmp->cost_a;
			cost.b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	execute_actions(stack_a, stack_b, &cost);
}
