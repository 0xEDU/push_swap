/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:23:40 by etachott          #+#    #+#             */
/*   Updated: 2022/11/15 15:26:51 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		ft_print("Usage: ./push_swap [NUMBERS TO BE SORTED]");
		exit(0);
	}
	if (!validate_input(argv))
	{
		ft_print("Invalid input!");
		exit(0);
	}
	stack_a = argv_to_stack(argv);
	sort_print(stack_a, stack_b);
	return (0);
}
