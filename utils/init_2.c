/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:36:19 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 15:41:02 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*init_stack(t_lst **lst)
{
	t_stack	*stack;
	t_lst	*temp;

	stack = malloc(1 * sizeof(t_stack));
	if (stack == NULL)
		exit(-1);
	stack->a = *lst;
	stack->a_size = set_size(*lst);
	stack->b = NULL;
	stack->b_size = 0;
	stack->size_g = set_size(*lst);
	stack->min = find_min_lst(*lst);
	stack->max = find_max_lst(*lst);
	temp = stack->a;
	while (temp->next)
		temp = temp->next;
	stack->key_nmbr = find_key_nmbr(stack);
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
	lst->previous = NULL;
	lst->index = 0;
	if (lst == NULL)
		exit(-1);
	while (argv[++i] && i <= argc)
	{
		value = ft_atoi(argv[i]);
		ft_addback(&lst, value);
	}
	addprevious(&lst);
	set_position(&lst);
	return (lst);
}
