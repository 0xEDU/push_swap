/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:19:46 by etachott          #+#    #+#             */
/*   Updated: 2022/12/07 13:50:35 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_extremes(char *argv[])
{
	int	max;
	int	min;
	int	index;

	max = 2147483647;
	min = -2147483648;
	index = 0;
	while (argv[index])
	{
		if (ft_atoi(argv[index]) > max || ft_atoi(argv[index]) < min)
			return (0);
		index++;
	}
	return (1);
}

static int	check_doubles(char *argv[])
{
	int	n;
	int	index;
	int	jindex;

	n = 0;
	index = 1;
	while (argv[index])
	{
		n = ft_atoi(argv[index]);
		jindex = index + 1;
		while (argv[jindex])
		{
			if (n == ft_atoi(argv[jindex]))
				return (0);
			jindex++;
		}
		index++;
	}
	return (1);
}

int	validate_input(char *argv[])
{
	int	index;

	index = 1;
	if (!check_doubles(argv))
		return (0);
	if (!check_extremes(argv))
		return (0);
	while (argv[index])
	{
		if (ft_atoi(argv[index]))
			index++;
		else if (ft_strnstr(argv[index], "0", ft_strlen(argv[index])))
			index++;
		else
			return (0);
	}
	return (index);
}

int	validate_quotes(char *argv[])
{
	char	**word_matrix;
	int		quotes;

	word_matrix = ft_split(argv[1], ' ');
	quotes = ft_matrixsize(word_matrix);
	ft_freematrix(word_matrix);
	if (quotes > 1)
		return (quotes);
	else
		return (0);
}
