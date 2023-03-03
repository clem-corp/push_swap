/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:50:36 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/03 08:29:59 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(enum e_lst_select lst_choose)
{
	if(lst_choose == a)
		ft_printf("a");
	else if(lst_choose == b)
		ft_printf("a");
	return ;
}


void ft_reduce_a(t_stack **stack)
{
    int min = (*stack)->min;
    int max = (*stack)->max;
    unsigned int i = 0;
    unsigned int j = 1;
	printf("%zu\n",(*stack)->a_size);
    while ((*stack)->a_size > 2)
    {
        if((*stack)->a->index <= j * (*stack)->key_nmbr && (*stack)->a->n != min && (*stack)->a->n != max)
		{
			ft_push(&((*stack)->a),&((*stack)->b));
			(*stack)->a_size = (*stack)->a_size - 1;
			(*stack)->b_size = (*stack)->b_size + 1;
			i++;
			if(i == j * (*stack)->key_nmbr)
				j++;
		}
		ft_rotate(&((*stack)->a));
    }
}

void	process_big(t_stack **stack)
{
	ft_reduce_a(stack);
	return;
}

void	ft_process(t_stack **stack)
{
	int	i;

	i = 0;
	if ((*stack)->size_g < 10)
		return;
	else if((*stack)->size_g > 10)
		process_big(stack);
	return;
}