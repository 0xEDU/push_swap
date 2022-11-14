/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:19:46 by etachott          #+#    #+#             */
/*   Updated: 2022/11/14 17:32:36 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(char *argv[])
{
	int	index;

	index = 1;
	while (argv[index])
	{
		if (ft_atoi(argv[index]))
			ft_printf("NUM!\n");
		else
			ft_printf("NOT NUM\n");
		index++;
	}
	return (0);
}
