/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move_from_stdin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:08:47 by etachott          #+#    #+#             */
/*   Updated: 2022/12/09 17:44:30 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_freematrix(char **matrix)
{
	int	index;

	index = 0;
	while (matrix[index])
	{
		free(matrix[index]);
		index++;
	}
	free(matrix);
}

char	**write_instructions(void)
{
	char	**valid_instructions;
	int		index;

	index = 0;
	valid_instructions = ft_calloc(sizeof(char *), 12);
	valid_instructions[0] = ft_strdup("sa\n");
	valid_instructions[1] = ft_strdup("sb\n");
	valid_instructions[2] = ft_strdup("ss\n");
	valid_instructions[3] = ft_strdup("pa\n");
	valid_instructions[4] = ft_strdup("pb\n");
	valid_instructions[5] = ft_strdup("ra\n");
	valid_instructions[6] = ft_strdup("rb\n");
	valid_instructions[7] = ft_strdup("rr\n");
	valid_instructions[8] = ft_strdup("rra\n");
	valid_instructions[9] = ft_strdup("rrb\n");
	valid_instructions[10] = ft_strdup("rrr\n");
	valid_instructions[11] = NULL;
	return (valid_instructions);
}

int	is_valid(char **valid_instructions, char *line)
{
	int	index;

	index = 0;
	while (valid_instructions[index])
	{
		if (!ft_strncmp(valid_instructions[index], line, ft_strlen(line)))
			return (1);
		index++;
	}
	return (0);
}

void	apply_op_to_stack(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa", 2))
		swap(stack_a);
	if (!ft_strncmp(line, "sb", 2))
		swap(stack_b);
	if (!ft_strncmp(line, "ss", 2))
		super_swap(stack_a, stack_b);
	if (!ft_strncmp(line, "rra", 3))
		reverse_rotate(stack_a);
	if (!ft_strncmp(line, "rrb", 3))
		reverse_rotate(stack_b);
	if (!ft_strncmp(line, "ra", 2))
		rotate(stack_a);
	if (!ft_strncmp(line, "rb", 2))
		rotate(stack_b);
	if (!ft_strncmp(line, "rr", 2) && ft_strlen(line) != 4)
		rotate_rotate(stack_a, stack_b);
	if (!ft_strncmp(line, "rrr", 3))
		reverse_rotate_rotate(stack_a, stack_b);
	if (!ft_strncmp(line, "pa", 2))
		push_a(stack_a, stack_b);
	if (!ft_strncmp(line, "pb", 2))
		push_b(stack_a, stack_b);
}

void	apply_move_from_stdin(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	char	**valid_instructions;

	valid_instructions = write_instructions();
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!is_valid(valid_instructions, line))
		{
			free(line);
			line = get_next_line(3);
			free(line);
			ft_freematrix(valid_instructions);
			ft_stackfree(stack_a);
			ft_stackfree(stack_b);
			exit(0);
		}
		apply_op_to_stack(stack_a, stack_b, line);
		free(line);
	}
	ft_freematrix(valid_instructions);
}
