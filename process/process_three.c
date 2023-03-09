/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:54:23 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 16:47:57 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_process_three_two(t_stack **stack)
{
	if ((*stack)->a->index == 1 && (*stack)->a->next->index == 0)
	{
		ft_swap(&(*stack)->a);
		ft_printf("sa\n");
	}
	else if ((*stack)->a->index == 0 && (*stack)->a->next->index == 2)
	{
		ft_reverse_rotate(&(*stack)->a);
		ft_swap(&(*stack)->a);
		ft_printf("rra\nsa\n");
	}
}

void	ft_process_three(t_stack **stack)
{
	if ((*stack)->a->index == 2 && (*stack)->a->next->index == 0)
	{
		ft_rotate(&(*stack)->a);
		ft_printf("ra\n");
	}
	else if ((*stack)->a->index == 2 && (*stack)->a->next->index == 1)
	{
		ft_rotate(&(*stack)->a);
		ft_swap(&(*stack)->a);
		ft_printf("ra\nsa\n");
	}
	else if ((*stack)->a->index == 1 && (*stack)->a->next->index == 2)
	{
		ft_reverse_rotate(&(*stack)->a);
		ft_printf("rra\n");
	}
	else
		ft_process_three_two(stack);
}

void	ft_process_three_reverse_two(t_stack **stack)
{
	if ((*stack)->b->index == 1 && (*stack)->b->next->index == 2)
	{
		ft_reverse_rotate(&(*stack)->b);
		ft_printf("rrb\n");
	}
	else if ((*stack)->b->index == 1 && (*stack)->b->next->index == 0)
	{
		ft_swap(&(*stack)->b);
		ft_printf("sb\n");
	}
	else if ((*stack)->b->index == 0 && (*stack)->b->next->index == 2)
	{
		ft_reverse_rotate(&(*stack)->b);
		ft_swap(&(*stack)->b);
		ft_printf("rrb\nsb\n");
	}
}

void	ft_process_three_reverse(t_stack **stack)
{
	if ((*stack)->b->index == 2 && (*stack)->b->next->index == 0)
	{
		ft_rotate(&(*stack)->b);
		ft_printf("rb\n");
	}
	else if ((*stack)->b->index == 2 && (*stack)->b->next->index == 1)
	{
		ft_rotate(&(*stack)->b);
		ft_swap(&(*stack)->b);
		ft_printf("rb\nsb\n");
	}
	else
		ft_process_three_reverse_two(stack);
	ft_rotate(&(*stack)->b);
	ft_swap(&(*stack)->b);
	ft_printf("rb\nsb\n");
}
