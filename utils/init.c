/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:15:52 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/28 18:41:49 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

size_t set_size(t_lst *lst)
{
    size_t size;
	
	size = 0;
    while (lst != NULL) {
        size++;
        lst = lst->next;
    }
    return size;
}

int find_min_lst(t_lst *lst) {
    int min;
	
	min = lst->n;
    while (lst != NULL) {
        if (lst->n < min) {
            min = lst->n;
        }
        lst = lst->next;
    }
    return min;
}

int find_max_lst(t_lst *lst) {
    int max;
	
	max = lst->n;
    while (lst != NULL) {
        if (lst->n > max) {
            max = lst->n;
        }
        lst = lst->next;
    }
    return max;
}

t_stack	*init_stack(t_lst **lst)
{
	t_stack	*stack;

	stack = malloc(1 * sizeof(t_stack));
	if (stack == NULL)
		exit(-1);
	stack->a = *lst;
	stack->b = NULL;
	stack->size_g = set_size(*lst);
	stack->min = find_min_lst(*lst);
	stack->max = find_max_lst(*lst);
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
	}
	return lst;
}
