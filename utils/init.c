/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:15:52 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 15:37:09 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	set_size(t_lst *lst)
{
	size_t	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	find_min_lst(t_lst *lst)
{
	int	min;

	min = lst->n;
	while (lst != NULL)
	{
		if (lst->n < min)
		{
			min = lst->n;
		}
		lst = lst->next;
	}
	return (min);
}

int	find_max_lst(t_lst *lst)
{
	int	max;

	max = lst->n;
	while (lst != NULL)
	{
		if (lst->n > max)
			max = lst->n;
		lst = lst->next;
	}
	return (max);
}

int	find_key_nmbr(t_stack *stack)
{
	if (stack->size_g <= 100)
		return ((stack->size_g - 2) / 5);
	else if (stack->size_g > 100 && stack->size_g < 500)
		return ((stack->size_g - 2) / 10);
	else if (stack->size_g >= 500)
		return ((stack->size_g - 2) / 12);
	return (0);
}

void	set_position(t_lst **lst)
{
	t_lst			*lst_here;
	unsigned int	position;

	lst_here = *lst;
	position = 0;
	while (lst_here->next)
	{
		lst_here->position = ++position;
		lst_here = lst_here->next;
	}
	lst_here->position = ++position;
}
