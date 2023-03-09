/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:36:46 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 17:36:25 by clacaill         ###   ########.fr       */
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

int	check_two(const int argc, const char **argv)
{
	int			i;
	int			j;
	long int	value;

	i = 0;
	j = 0;
	value = 0;
	while (argv[++i] && i <= argc)
	{
		value = ft_atoi(argv[i]);
		if (value > N_MAX || value < N_MIN)
			return (0);
		j = i + 1;
		while (argv[j] && j <= argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (0);
			j++;
		}
	}
	return (1);
}

// succes = 1 ||||| echec = 0
int	stack_checker(const int argc, const char **argv)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (argv[++i] && i <= argc)
	{
		while (argv[i][j] && is_digit(argv[i][j]) == 1)
			j++;
		if (argv[i][j] != '\0')
			return (0);
		j = 0;
	}
	return (check_two((const int) argc, (const char **) argv));
}

// Already order ? 1 : 0
int	ft_already_order(const char **argv)
{
	int			i;
	long int	value;
	long int	value2;

	i = 1;
	value = 0;
	value2 = 1;
	while (argv[i] && (value < value2))
	{
		value = ft_atoi(argv[i]);
		if (argv[i + 1])
			value2 = ft_atoi(argv[i + 1]);
		i++;
	}
	if (!argv[i])
		return (1);
	return (0);
}
