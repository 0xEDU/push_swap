/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:49:20 by etachott          #+#    #+#             */
/*   Updated: 2022/12/09 17:43:03 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

void	error(void)
{
	ft_print("Error");
	exit(0);
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
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		quotes;

	if (argc < 2)
		exit(0);
	stack_size = validate_input(argv);
	if (argc == 2)
		quotes = validate_quotes(argv);
	if (!stack_size)
		error();
	stack_a = init_stack(argv, argc, stack_size);
	stack_b = NULL;
	apply_move_from_stdin(&stack_a, &stack_b);
	if (is_sorted(stack_a))
		ft_print("OK");
	else
		ft_print("KO");
	ft_stackfree(&stack_a);
	if (stack_b)
		ft_stackfree(&stack_b);
	return (0);
}
