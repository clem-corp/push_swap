/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:59:10 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 16:48:53 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_process_sm_five_two(t_stack **stack)
{
	if ((*stack)->a->index - 2 == 1 && (*stack)->a->next->index - 2 == 2)
	{
		ft_reverse_rotate(&(*stack)->a);
		ft_printf("rra\n");
	}
	else if ((*stack)->a->index - 2 == 1 && (*stack)->a->next->index - 2 == 0)
	{
		ft_swap(&(*stack)->a);
		ft_printf("sa\n");
	}
	else if ((*stack)->a->index - 2 == 0 && (*stack)->a->next->index - 2 == 2)
	{
		ft_reverse_rotate(&(*stack)->a);
		ft_swap(&(*stack)->a);
		ft_printf("rra\nsa\n");
	}
}

void	ft_process_sm_five(t_stack **stack)
{
	if ((*stack)->a->index - 2 == 2 && (*stack)->a->next->index - 2 == 0)
	{
		ft_rotate(&(*stack)->a);
		ft_printf("ra\n");
	}
	else if ((*stack)->a->index - 2 == 2 && (*stack)->a->next->index - 2 == 1)
	{
		ft_rotate(&(*stack)->a);
		ft_swap(&(*stack)->a);
		ft_printf("ra\nsa\n");
	}
	else
		ft_process_sm_five_two(stack);
}

void	ft_process_five(t_stack **stack)
{
	while ((*stack)->b_size != 2)
	{
		if ((*stack)->a->index == 0 || (*stack)->a->index == 1)
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
	ft_process_sm_five(stack);
	if ((*stack)->b->index == 0)
	{
		ft_swap(&((*stack)->b));
		ft_printf("sb\n");
	}
	ft_push(&((*stack)->b), &((*stack)->a));
	ft_printf("pa\n");
	ft_push(&((*stack)->b), &((*stack)->a));
	ft_printf("pa\n");
}
