/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:49:20 by etachott          #+#    #+#             */
/*   Updated: 2022/12/07 14:12:10 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

void	error(void)
{
	ft_print("Error");
	exit(0);
}

void	add_node_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

static int	is_sorted(t_stack *head)
{
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

static t_stack	*init_stack(char *argv[], int argc, int stack_size)
{
	t_stack	*stack;

	stack = argv_to_stack(argv, argc, stack_size);
	if (!stack)
		return (NULL);
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	int		stack_size;
	int		quotes;

	if (argc < 2)
		error();
	stack_size = validate_input(argv);
	if (argc == 2)
		quotes = validate_quotes(argv);
	if (!stack_size)
		error();
	stack = init_stack(argv, argc, stack_size);
	print_stack(stack);
	apply_move_from_stdin(&stack);
	if (is_sorted(stack))
		ft_print("OK");
	else
		ft_print("KO");
	ft_stackfree(&stack);
	return (0);
}
