/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:18:45 by etachott          #+#    #+#             */
/*   Updated: 2022/12/01 00:28:57 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rotate_rotate(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	while (cost->a > 0 && cost->b > 0)
	{
		cost->a--;
		cost->b--;
		rotate_rotate(stack_a, stack_b);
	}
}

void	exec_reverse_rotate_rotate(t_stack **stack_a,
		t_stack **stack_b, t_cost *cost)
{
	while (cost->a < 0 && cost->b < 0)
	{
		cost->a++;
		cost->b++;
		reverse_rotate_rotate(stack_a, stack_b);
	}
}

void	exec_b(t_stack **stack_b, t_cost *cost)
{
	while (cost->b)
	{
		if (cost->b > 0)
		{
			cost->b--;
			rotate_b(stack_b);
		}
		else if (cost->b < 0)
		{
			cost->b++;
			reverse_rotate_b(stack_b);
		}
	}
}

void	exec_a(t_stack **stack_a, t_cost *cost)
{
	while (cost->a)
	{
		if (cost->a > 0)
		{
			cost->a--;
			rotate_a(stack_a);
		}
		else if (cost->a < 0)
		{
			cost->a++;
			reverse_rotate_a(stack_a);
		}
	}
}
