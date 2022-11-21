/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:23:40 by etachott          #+#    #+#             */
/*   Updated: 2022/11/21 17:27:11 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *head)
{
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	init_index(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		index;

	tmp1 = *stack;
	while (tmp1)
	{
		index = 1;
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				index++;
			tmp2 = tmp2->next;
		}
		tmp1->index = index;
		tmp1 = tmp1->next;
	}
}

t_stack	*init_stack(char *argv[], int stack_size)
{
	t_stack	*stack;

	stack = argv_to_stack(argv, stack_size);
	init_index(&stack);
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc <= 2)
		exit(0);
	stack_size = validate_input(argv);
	if (!stack_size)
	{
		ft_print("Error");
		exit(0);
	}
	stack_a = init_stack(argv, stack_size);
	stack_b = NULL;
	ft_print("BEFORE");
	print_stack(stack_a);
	ft_print("");
	print_stack(stack_b);
	ft_print("");
	sort(&stack_a, &stack_b, stack_size - 1);
	ft_print("AFTER");
	print_stack(stack_a);
	ft_print("");
	print_stack(stack_b);
	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	return (0);
}
