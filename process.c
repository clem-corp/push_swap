/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:50:36 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/07 19:14:39 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(enum e_lst_select lst_choose)
{
	if(lst_choose == a)
		ft_printf("a");
	else if(lst_choose == b)
		ft_printf("b");
	return ;
}

int	ft_rotate_or_reverse(t_stack **stack, t_lst	**lst, unsigned int j)
{
	t_lst	*temp;
	int		i;

	temp = *lst;
	i = 0;
	while(temp)
	{
		if(temp->index > j * (*stack)->key_nmbr || temp->n == (*stack)->min || temp->n == (*stack)->max)
			temp = temp->next;
		else
		{
			if(temp && temp->position > (set_size(temp) / 2))
				return (-1);
			else
				return (1);
		}
	}
	return (0);
}

void ft_reduce_a(t_stack **stack)
{
    int min = (*stack)->min;
    int max = (*stack)->max;
    unsigned int i = 0;
    unsigned int j = 1;
    while ((*stack)->a_size > 2)
    {
        if((*stack)->a->index <= j * (*stack)->key_nmbr && (*stack)->a->n != min && (*stack)->a->n != max)
		{
			ft_push(&((*stack)->a),&((*stack)->b));
			ft_printf("pb\n");
			(*stack)->a_size = (*stack)->a_size - 1;
			(*stack)->b_size = (*stack)->b_size + 1;
			i++;
		}
		if(i >= j * (*stack)->key_nmbr)
			j++;
		//have to find if rotate or rotate reverse
		if(ft_rotate_or_reverse(stack, &((*stack)->a), j) == 1 && (*stack)->a_size > 2)
		{
			ft_rotate(&((*stack)->a));
			ft_printf("ra\n");
		}
		else if(ft_rotate_or_reverse(stack, &((*stack)->a), j) == -1 && (*stack)->a_size > 2)
		{
			ft_reverse_rotate(&((*stack)->a));	
			ft_printf("rra\n");
		}
    }
	if((*stack)->a->index < (*stack)->a->next->index)
	{
		ft_rotate(&((*stack)->a));
		ft_printf("ra\n");
	}
}

int	ft_rotate_or_reverse2(t_lst	**lst, unsigned int j)
{
	t_lst	*temp;
	int		i;

	temp = *lst;
	i = 0;
	while(temp)
	{
		if(temp && temp->index != j)
			temp = temp->next;
		else if(temp && temp->position)
		{
			if(temp && temp->position > (set_size(temp) / 2))
				return (-1);
			else
				return (1);
		}
	}
	return (0);
}

void ft_fill_a(t_stack **stack)
{
    unsigned int j = (*stack)->b_size;
    while ((*stack)->b_size > 0 && (*stack)->a_size < (*stack)->size_g)
    {
        if((*stack)->b->index == j)
		{
			ft_push(&((*stack)->b),&((*stack)->a));
			ft_printf("pa\n");
			(*stack)->b_size = (*stack)->b_size - 1;
			(*stack)->a_size = (*stack)->a_size + 1;
			j--;
		}
		//have to find if rotate or rotate reverse
		if(ft_rotate_or_reverse2(&((*stack)->b), j) == 1 && (*stack)->b_size > 0)
		{
			ft_rotate(&((*stack)->b));
			ft_printf("rb\n");
		}
		else if(ft_rotate_or_reverse2(&((*stack)->b), j) == -1 && (*stack)->b_size > 0)
		{
			ft_reverse_rotate(&((*stack)->b));	
			ft_printf("rrb\n");
		}
    }
	ft_reverse_rotate(&((*stack)->a));
	ft_printf("rra\n");
}

void	process_big(t_stack **stack)
{
	ft_reduce_a(stack);
	ft_fill_a(stack);
	return;
}

void	ft_process(t_stack **stack)
{
	int	i;

	i = 0;
	// small @todo
	if ((*stack)->size_g < 10)
		return;
	else if((*stack)->size_g > 10)
		process_big(stack);
	return;
}