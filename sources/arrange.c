/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:22:07 by etachott          #+#    #+#             */
/*   Updated: 2022/12/01 02:26:02 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_lowest_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		position;
	int		lowest_index;

	tmp = *stack;
	lowest_index = tmp->index;
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
	ft_print("Position = %d", position);
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
		ft_print("inside if");
		while (lowest_pos < size)
		{
			reverse_rotate_a(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		ft_print("inside else");
		while (lowest_pos > 0)
		{
			rotate_a(stack_a);
			lowest_pos--;
		}
	}
}
