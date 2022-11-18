/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:23:40 by etachott          #+#    #+#             */
/*   Updated: 2022/11/18 17:42:37 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stack_a = argv_to_stack(argv, stack_size);
	stack_b = argv_to_stack(argv, stack_size);
//	swap(&stack_a);
	ft_print("BEFORE");
	print_stack(stack_a);
	ft_print("");
	print_stack(stack_b);
	rotate_rotate(&stack_a, &stack_b);
	ft_print("");
	ft_print("AFTER");
	print_stack(stack_a);
	ft_print("");
	print_stack(stack_b);
//	sort_print(stack_a, stack_b);
	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	return (0);
}
