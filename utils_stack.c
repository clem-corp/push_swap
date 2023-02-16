/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:25:17 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/16 04:57:26 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_lst **stack)
{
	t_lst	*temp;

	if (!*stack || (*stack)->next == NULL)
		return;
	temp = (*stack);
	temp->next = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	return;
}

void    ft_push(t_lst **orig, t_lst **dest)
{
    t_lst   *temp;

    if (!*orig)
		return ;
	temp = *orig;
    (*orig) = (*orig)->next;
    temp->next = *dest;
    *dest = temp;
    return ;
}

void    ft_rotate(t_lst **stack)
{
	t_lst	*temp;

	if (!*stack)
		return;
	temp = *stack;
	while(temp->next)
		temp = temp->next;
	if (*stack != temp)
	{
		temp->next = *stack;
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
	}
	return;
}

void    ft_reverse_rotate(t_lst **stack)
{
	t_lst	*temp;

	if (!*stack)
		return;
	temp = *stack;
	while((*stack)->next && (*stack)->next->next)
		(*stack) = (*stack)->next;
	if (*stack != temp)
	{
		(*stack)->next->next = temp; 
		temp = (*stack)->next;
		(*stack)->next = NULL;
		*stack = temp;
	}
	return;
}