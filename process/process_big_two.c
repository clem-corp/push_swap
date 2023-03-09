/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_big_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:29:03 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 17:07:09 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reduce_a(t_stack **stack)
{
	int				min;
	int				max;
	unsigned int	i;
	unsigned int	j;

	min = (*stack)->min;
	max = (*stack)->max;
	i = 0;
	j = 1;
	while ((*stack)->a_size > 2)
	{
		if ((*stack)->a->index <= j * (*stack)->key_nmbr
			&& (*stack)->a->n != min && (*stack)->a->n != max)
		{
			ft_reduce_a_first(stack);
			i++;
		}
		else if (i >= j * (*stack)->key_nmbr)
			j++;
		else if ((*stack)->a_size > 2
			&& (ft_rotate_or_reverse(stack, &((*stack)->a), j) == 1
				|| ft_rotate_or_reverse(stack, &((*stack)->a), j) == -1))
			ft_reduce_a_min(stack, j);
	}
	ft_reduce_a_last(stack);
}

void	ft_fill_a_mini(t_stack **stack)
{
	unsigned int	j;

	j = (*stack)->b_size;
	if ((*stack)->b->index == j)
	{
		ft_push(&((*stack)->b), &((*stack)->a));
		ft_printf("pa\n");
		(*stack)->b_size = (*stack)->b_size - 1;
		(*stack)->a_size = (*stack)->a_size + 1;
		j--;
	}
	else if (ft_rotate_or_reverse2(&((*stack)->b), j) == 1
		&& (*stack)->b_size > 0)
	{
		ft_rotate(&((*stack)->b));
		ft_printf("rb\n");
	}
	else if (ft_rotate_or_reverse2(&((*stack)->b), j) == -1
		&& (*stack)->b_size > 0)
	{
		ft_reverse_rotate(&((*stack)->b));
		ft_printf("rrb\n");
	}
}

void	ft_fill_a(t_stack **stack)
{
	while ((*stack)->b_size > 0 && (*stack)->a_size < (*stack)->size_g)
		ft_fill_a_mini(stack);
	ft_reverse_rotate(&((*stack)->a));
	ft_printf("rra\n");
}
