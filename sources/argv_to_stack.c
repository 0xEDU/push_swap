/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:37:28 by etachott          #+#    #+#             */
/*   Updated: 2022/11/15 16:35:36 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*argv_to_stack(char *argv[], int stack_size)
{
	t_stack	*stack;
	int		index_s;
	int		index_a;

	stack = malloc(sizeof (t_stack) * stack_size + 1);
	index_s = 0;
	index_a = 1;
	while (argv[index_a])
	{
		stack[index_s].value = ft_atoi(argv[index_a]);
		stack[index_s].index = index_s;
	}
	return (stack);
}
