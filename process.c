/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:50:36 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 13:49:31 by clacaill         ###   ########.fr       */
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

	temp = *lst;
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
		else if(i >= j * (*stack)->key_nmbr)
			j++;
		//have to find if rotate or rotate reverse
		else if(ft_rotate_or_reverse(stack, &((*stack)->a), j) == 1 && (*stack)->a_size > 2)
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

	temp = *lst;
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
		else if(ft_rotate_or_reverse2(&((*stack)->b), j) == 1 && (*stack)->b_size > 0)
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

void	ft_process_big(t_stack **stack)
{
	ft_reduce_a(stack);
	ft_fill_a(stack);
	return;
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
	else if ((*stack)->a->index == 1 && (*stack)->a->next->index == 0)
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
	else if ((*stack)->b->index == 1 && (*stack)->b->next->index == 2)
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
	// 0 1 2
	ft_rotate(&(*stack)->b);
	ft_swap(&(*stack)->b);
	ft_printf("rb\nsb\n");
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
	else if ((*stack)->a->index - 2 == 1 && (*stack)->a->next->index - 2 == 2)
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

void	ft_process_sm_six(t_stack **stack)
{
	if ((*stack)->a->index - 3 == 2 && (*stack)->a->next->index - 3 == 0)
	{
		ft_rotate(&(*stack)->a);
		ft_printf("ra\n");
	}
	else if ((*stack)->a->index - 3 == 2 && (*stack)->a->next->index - 3 == 1)
	{
		ft_rotate(&(*stack)->a);
		ft_swap(&(*stack)->a);
		ft_printf("ra\nsa\n");
	}
	else if ((*stack)->a->index - 3 == 1 && (*stack)->a->next->index - 3 == 2)
	{
		ft_reverse_rotate(&(*stack)->a);
		ft_printf("rra\n");
	}
	else if ((*stack)->a->index - 3 == 1 && (*stack)->a->next->index - 3 == 0)
	{
		ft_swap(&(*stack)->a);
		ft_printf("sa\n");
	}
	else if ((*stack)->a->index - 3 == 0 && (*stack)->a->next->index - 3 == 2)
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
	else if ((*stack)->a->index - 1 == 1 && (*stack)->a->next->index - 1 == 0)
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

void	ft_process_five(t_stack **stack)
{
	while((*stack)->b_size != 2)
	{
		if ((*stack)->a->index == 0 || (*stack)->a->index == 1)
		{
			ft_push(&((*stack)->a),&((*stack)->b));
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
	ft_push(&((*stack)->b),&((*stack)->a));
	ft_printf("pa\n");
	ft_push(&((*stack)->b),&((*stack)->a));
	ft_printf("pa\n");
}

void	ft_process_four(t_stack **stack)
{
	while((*stack)->b_size != 1)
	{
		if ((*stack)->a->index == 0)
		{
			ft_push(&((*stack)->a),&((*stack)->b));
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
	ft_push(&((*stack)->b),&((*stack)->a));
	ft_printf("pa\n");
}

void	ft_process_six(t_stack **stack)
{
	while((*stack)->b_size != 3)
	{
		if ((*stack)->a->index == 0 || (*stack)->a->index == 1 || (*stack)->a->index == 2)
		{
			ft_push(&((*stack)->a),&((*stack)->b));
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
	ft_process_sm_six(stack);
	ft_process_three_reverse(stack);
	ft_push(&((*stack)->b),&((*stack)->a));
	ft_push(&((*stack)->b),&((*stack)->a));
	ft_push(&((*stack)->b),&((*stack)->a));
	ft_printf("pa\npa\npa\n");
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
		return;
	}
	else if ((*stack)->size_g == 3)
		ft_process_three(stack);
	else if ((*stack)->size_g == 4)
		ft_process_four(stack);
	else if ((*stack)->size_g == 5)
		ft_process_five(stack);
	else if ((*stack)->size_g == 6)
		ft_process_six(stack);
	else if((*stack)->size_g > 6)
		ft_process_big(stack);
	return;
}
