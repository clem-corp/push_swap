/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:15:52 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/03 10:22:23 by clacaill         ###   ########.fr       */
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

int find_max_lst(t_lst *lst)
{
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

int		find_key_nmbr(t_stack *stack)
{
	if(stack->size_g < 100)
		return((stack->size_g - 2) / 4);
	else if(stack->size_g > 100 && stack->size_g < 300)
		return((stack->size_g - 2) / 10);
	else if(stack->size_g > 300 && stack->size_g < 500)
		return((stack->size_g - 2) / 20);
	else if(stack->size_g > 500)
		return((stack->size_g - 2) / 30);
	return (0);
}

void	set_position(t_lst **lst)
{
	t_lst	*lst_here;
	lst_here = *lst;
	int position = 0;
	while(lst_here->next)
	{
		lst_here->position = ++position;
		lst_here = lst_here->next;
	}
	lst_here->position = ++position;
}

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
	//free(temp);
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
	if(lst == NULL)
		exit(-1);
	while(argv[++i] && i <= argc)
	{
		value = ft_atoi(argv[i]);
		ft_addback(&lst, value);
	}
	addPrevious(&lst);
	set_position(&lst);
	return lst;
}
