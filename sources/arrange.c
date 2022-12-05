/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:22:07 by etachott          #+#    #+#             */
/*   Updated: 2022/12/05 10:45:12 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_lowest_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		position;
	int		lowest_index;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_current_pos(stack);
	position = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			position = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (position);
}

void	arrange_stack(t_stack **stack_a)
{
	int	size;
	int	lowest_pos;

	size = ft_stacksize(*stack_a);
	lowest_pos = get_lowest_pos(stack_a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			reverse_rotate_a(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate_a(stack_a);
			lowest_pos--;
		}
	}
}
