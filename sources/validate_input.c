/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:19:46 by etachott          #+#    #+#             */
/*   Updated: 2022/11/17 14:47:40 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(char *argv[])
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
	while (argv[index])
	{
		if (ft_atoi(argv[index]))
			index++;
		else
			return (0);
	}
	return (index);
}
