/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:22 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 16:48:36 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_process_sm_four_two(t_stack **stack)
{
	if ((*stack)->a->index - 1 == 1 && (*stack)->a->next->index - 1 == 0)
	{
		ft_swap(&(*stack)->a);
		ft_printf("sa\n");
	}
	else if ((*stack)->a->index - 1 == 0 && (*stack)->a->next->index - 1 == 2)
	{
		ft_reverse_rotate(&(*stack)->a);
		ft_swap(&(*stack)->a);
		ft_printf("rra\nsa\n");
	}
}

void	ft_process_sm_four(t_stack **stack)
{
	if ((*stack)->a->index - 1 == 2 && (*stack)->a->next->index - 1 == 0)
	{
		ft_rotate(&(*stack)->a);
		ft_printf("ra\n");
	}
	else if ((*stack)->a->index - 1 == 2 && (*stack)->a->next->index - 1 == 1)
	{
		ft_rotate(&(*stack)->a);
		ft_swap(&(*stack)->a);
		ft_printf("ra\nsa\n");
	}
	else if ((*stack)->a->index - 1 == 1 && (*stack)->a->next->index - 1 == 2)
	{
		ft_reverse_rotate(&(*stack)->a);
		ft_printf("rra\n");
	}
	else
		ft_process_sm_four_two(stack);
}

void	ft_process_four(t_stack **stack)
{
	while ((*stack)->b_size != 1)
	{
		if ((*stack)->a->index == 0)
		{
			ft_push(&((*stack)->a), &((*stack)->b));
			ft_printf("pb\n");
			(*stack)->a_size = (*stack)->a_size - 1;
			(*stack)->b_size = (*stack)->b_size + 1;
		}
		else
		{
			ft_rotate(&((*stack)->a));
			ft_printf("ra\n");
		}
	}
	ft_process_sm_four(stack);
	ft_push(&((*stack)->b), &((*stack)->a));
	ft_printf("pa\n");
}
