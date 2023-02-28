/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:31:27 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/28 17:37:33 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

size_t lst_len(t_lst *lst)
{
    size_t size;
	
	size = 0;
    while (lst != NULL) {
        size++;
        lst = lst->next;
    }
    return size;
}

void	free_lst(t_lst **first)
{
	size_t	i;
	t_lst	*tmp;

	i = lst_len(*first);
	while (i-- > 0)
	{
		tmp = (*first)->next;
		free(*first);
		*first = tmp;
	}
	*first = NULL;
}

void	*free_stack(t_stack **stack)
{
	free_lst(&(*stack)->a);
	(*stack)->a = NULL;
	free_lst(&(*stack)->b);
	(*stack)->b = NULL;
	free(*stack);
	*stack = NULL;
	return (NULL);
}