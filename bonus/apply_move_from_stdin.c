/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move_from_stdin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:08:47 by etachott          #+#    #+#             */
/*   Updated: 2022/12/07 14:34:43 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	write_instructions(char **valid_instructions)
{
	int	index;

	index = 0;
	valid_instructions = ft_calloc((sizeof char *), 12);
	while (index < 12)
	{
		valid_instructions[index] = ft_calloc((sizeof char), 4);
		index++;
	}
}

void	apply_move_from_stdin(t_stack **stack)
{
	char	*line;
	char	**valid_instructions;

	(void)stack;
	write_instructions(valid_instructions);
	ft_print("%s", valid_instructions[0]);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_printf("LINE = %s", line);
		free(line);
	}
}
