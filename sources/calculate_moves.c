/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:50:13 by etachott          #+#    #+#             */
/*   Updated: 2022/12/01 01:26:07 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* First, calculate the cost for the element to be at the top of stack b, then 
 * calculate the cost of putting the target_pos at the top of a.
 */

int	ft_stacksize(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	tmp = stack;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	calculate_move_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		size_a;
	int		size_b;

	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		tmp->cost_b = tmp->pos;
		if (tmp->pos > size_b / 2)
			tmp->cost_b = (size_b - tmp->pos) * -1;
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > size_a / 2)
			tmp->cost_a = (size_a - tmp->target_pos) * -1;
		tmp = tmp->next;
	}
}
