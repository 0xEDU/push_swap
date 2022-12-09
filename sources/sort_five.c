/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:46:02 by etachott          #+#    #+#             */
/*   Updated: 2022/12/09 19:09:04 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	tmp = stack;
	if (!stack)
		return (0);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

static int	get_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

static int	get_max(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value > min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	min = get_min(*stack_a);
	max = get_max(*stack_a);
	while (stack_size(*stack_b) < 2)
	{
		if ((*stack_a)->value == min || (*stack_a)->value == max)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_threes(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	if ((*stack_a)->value == max)
		rotate_a(stack_a);
	else
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
}
