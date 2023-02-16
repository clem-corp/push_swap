/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:31:27 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/16 09:53:30 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	*free_stack(t_stack **stack)
{
	// free_lst(&(*stack)->a);
	(*stack)->a = NULL;
	// free_lst(&(*stack)->b);
	(*stack)->b = NULL;
	free(*stack);
	*stack = NULL;
	return (NULL);
}