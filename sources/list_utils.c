/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:28:39 by etachott          #+#    #+#             */
/*   Updated: 2022/11/17 14:15:26 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackfree(t_stack **stack)
{
	t_stack	*prev_node;

	prev_node = *stack;
	while (*stack && prev_node)
	{
		prev_node = *stack;
		*stack = (*stack)->next;
		free(prev_node);
	}
	*stack = NULL;
}
