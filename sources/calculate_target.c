/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:50:55 by etachott          #+#    #+#             */
/*   Updated: 2022/11/23 17:50:56 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_in_a(t_stack **stack_a, int index_b, int clos_idx, int pos)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < clos_idx)
		{
			clos_idx = tmp->index;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (clos_idx != INT_MAX)
		return (pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < clos_idx)
		{
			clos_idx = tmp->index;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos);
}

void	calculate_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		position;

	tmp = *stack_b;
	position = 0;
	while (tmp)
	{
		position = search_in_a(stack_a, tmp->index, INT_MAX, position);
		tmp->target_pos = position;
		tmp = tmp->next;
	}
}
