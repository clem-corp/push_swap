/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:50:36 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 16:14:01 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_process_big(t_stack **stack)
{
	ft_reduce_a(stack);
	ft_fill_a(stack);
	return ;
}

void	ft_process(t_stack **stack)
{
	if ((*stack)->size_g == 2)
	{
		if ((*stack)->a->index == 1)
		{
			ft_swap(&((*stack)->a));
			ft_printf("sa\n");
		}
		return ;
	}
	else if ((*stack)->size_g == 3)
		ft_process_three(stack);
	else if ((*stack)->size_g == 4)
		ft_process_four(stack);
	else if ((*stack)->size_g == 5)
		ft_process_five(stack);
	else if ((*stack)->size_g == 6)
		ft_process_six(stack);
	else if ((*stack)->size_g > 6)
		ft_process_big(stack);
	return ;
}
