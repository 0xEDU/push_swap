/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:23:40 by etachott          #+#    #+#             */
/*   Updated: 2022/11/17 14:26:37 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		stack_size;
//	t_stack	*stack_b;

	if (argc < 2)
		exit(0);
	stack_size = validate_input(argv);
	if (!stack_size)
	{
		ft_print("Error");
		exit(0);
	}
	stack_a = argv_to_stack(argv, stack_size);
	ft_print("BEFORE SWAP");
	print_stack(stack_a);
	swap(&stack_a);
	ft_print("\nAFTER SWAP");
	print_stack(stack_a);
	//free(stack_a->next);
	ft_stackfree(&stack_a);
//	sort_print(stack_a, stack_b);
	return (0);
}
