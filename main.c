/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:35:36 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/16 04:41:33 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* A mettre dans ft_checker.c */
int	is_digit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

// succes = 1 :::: echec = 0
int	stack_checker(const int argc, const char **argv)
{
	int	i;
	int j;
	long int value;

	i = 0;
	j = 0;
	// checker les non chiffres
	while (argv[++i] && i <= argc)
	{
		while(argv[i][++j] && is_digit(argv[i][j]) == 1);
		if(argv[i][j] != '\0')
			return (0);
	}
	i = 0;
	// checker les doublons
	while (argv[++i] && i <= argc)
	{
		j = 0;
		value = ft_atoi(argv[i]);
		if(value > INT_MAX || value < INT_MIN)
		while (argv[++j] && j <= argc)
			if(i != j && argv[j] == argv[i] )
				return (0);
	}
	return (1);
}
/* Fin de mettre dans ft_checker*/

int	main(int argc, char **argv)
{
	// t_stack	*stack;

	if (argc < 2)
		return (ft_printf("Error.\n"));
	/* if (argc == 2)
		one_arg_checker(argv); */
	else
	{
		/* la ya tout a gerer  */
		if (stack_checker((const int)argc, (const char **)argv) == 0)
			return (0);
	}
	// free_stack(&stack);
	return (0);
}
