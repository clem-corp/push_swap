/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:36:46 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/28 16:13:12 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// succes = 1 ||||| echec = 0
int	is_digit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

// succes = 1 ||||| echec = 0
int	stack_checker(const int argc, const char **argv)
{
	int	i;
	int j;
	long int value;
	long int value2;

	i = 0;
	j = -1;
	value = 0;
	value2 = 0;
	// checker les non chiffres
	while (argv[++i] && i <= argc)
	{
		while(argv[i][++j] && is_digit(argv[i][j]) == 1);
		if(argv[i][j] != '\0')
			return (0);
		j = -1;
	}
	i = 0;
	// checker les doublons
	while (argv[++i] && i <= argc)
	{
		j = 0;
		value = ft_atoi(argv[i]);
		if(value > N_MAX || value < N_MIN)
			return (0);
		while (argv[++j] && j <= argc)
			if(i != j && ft_atoi(argv[j]) == ft_atoi(argv[i]))
			return (0);
	}
	return (1);
}

// Already order ? 1 : 0
int	already_order(const char **argv)
{
	int			i;
	long int	value;
	long int	value2;

	i = 0;
	value = 0;
	value2 = 1;
	while(argv[i] && (value < value2))
	{
		value = ft_atoi(argv[i]);
		if(argv[i + 1])
			value2 = ft_atoi(argv[i + 1]);
		i++;
	}
	if (!argv[i])
		return (1);
	return (0);
}