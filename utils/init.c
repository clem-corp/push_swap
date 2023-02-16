/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:15:52 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/16 12:41:12 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

t_stack	*init_stack(t_lst **lst)
{
	t_stack	*stack;

	stack = malloc(1 * sizeof(t_stack));
	if (stack == NULL)
		exit(-1);
	stack->a = *lst;
	stack->b = NULL;
	stack->g_count = 0;
	stack->a_size = 0;
	stack->a_min = N_MAX;
	stack->a_max = N_MIN;
	stack->b_size = 0;
	stack->b_min = N_MAX;
	stack->b_max = N_MIN;
	return (stack);
}

t_lst	*init_lst(int argc, const char **argv)
{
	t_lst	*lst;
	int		value;
	int		i;

	i = 1;
	lst = malloc(1 * sizeof(t_lst));
	lst->n = ft_atoi(argv[1]);
	lst->next = NULL;
	lst->index = 0;
	if(lst == NULL)
		exit(-1);
	while(argv[++i] && i <= argc)
	{
		value = ft_atoi(argv[i]);
		ft_addback(&lst, value);
		i++;
	}
	return lst;
}

void	fill_stack(t_stack **stack, int argc, const char **argv)
{
	if (*stack == NULL)
		exit(-1);
	(*stack)->g_count = argc;
	if((*stack)->a != NULL)
	{
		(*stack)->a_size = find_size((*stack)->a);
		(*stack)->a_min = find_min_lst((*stack)->a);
		(*stack)->a_max = find_max_lst((*stack)->a);
	}
	if((*stack)->b != NULL)
	{
		(*stack)->b_size = find_size((*stack)->b);
		(*stack)->b_min = find_min_lst((*stack)->b);
		(*stack)->b_max = find_max_lst((*stack)->b);
	}
	return (stack);
}