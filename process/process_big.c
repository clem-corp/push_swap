/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:56:21 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 16:29:52 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rotate_or_reverse(t_stack **stack, t_lst	**lst, unsigned int j)
{
	t_lst	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->index > j * (*stack)->key_nmbr || temp->n == (*stack)->min
			|| temp->n == (*stack)->max)
				temp = temp->next;
		else
		{
			if (temp && temp->position > (set_size(temp) / 2))
				return (-1);
			else
				return (1);
		}
	}
	return (0);
}

int	ft_rotate_or_reverse2(t_lst	**lst, unsigned int j)
{
	t_lst	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp && temp->index != j)
			temp = temp->next;
		else if (temp && temp->position)
		{
			if (temp && temp->position > (set_size(temp) / 2))
				return (-1);
			else
				return (1);
		}
	}
	return (0);
}

void	ft_reduce_a_first(t_stack **stack)
{
	ft_push(&((*stack)->a), &((*stack)->b));
	ft_printf("pb\n");
	(*stack)->a_size = (*stack)->a_size - 1;
	(*stack)->b_size = (*stack)->b_size + 1;
}

void	ft_reduce_a_min(t_stack **stack, unsigned int j)
{
	if (ft_rotate_or_reverse(stack, &((*stack)->a), j) == 1
		&& (*stack)->a_size > 2)
	{
		ft_rotate(&((*stack)->a));
		ft_printf("ra\n");
	}
	else if (ft_rotate_or_reverse(stack, &((*stack)->a), j) == -1
		&& (*stack)->a_size > 2)
	{
		ft_reverse_rotate(&((*stack)->a));
		ft_printf("rra\n");
	}
}

void	ft_reduce_a_last(t_stack **stack)
{
	if ((*stack)->a->index < (*stack)->a->next->index)
	{
		ft_rotate(&((*stack)->a));
		ft_printf("ra\n");
	}
}
