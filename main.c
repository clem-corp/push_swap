/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:35:36 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/16 07:13:34 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* A mettre dans ft_checker.c */
int	already_order(const char **argv)
{
	int			i;
	long int	value;
	long int	value2;

	i = 0;
	value = 0;
	value2 = 1;
	while(argv[++i] && (value < value2))
	{
		value = ft_atoi(argv[i]);
		if(argv[i + 1])
			value2 = ft_atoi(argv[i + 1]);
	}
	if (!argv[i])
		return (1);
	return (0);
}
/* Fin de mettre dans ft_checker*/

int	main(int argc, const char **argv)
{
	// t_stack	*stack;
	if (argc < 2)
		return (ft_printf("Error\n"));
	else
	{
		/* la ya tout a gerer  */
		if (stack_checker((const int)argc, (const char **)argv) == 0)
			return (ft_printf("Error\n"));
		if (already_order(argv) == 1)
			return (ft_printf(""));
	}
	// free_stack(&stack);
	return (ft_printf("SUCCESS 2.0\n"));
}
