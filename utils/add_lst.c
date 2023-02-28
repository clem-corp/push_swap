/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:53:16 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/28 18:45:35 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	ft_addback(t_lst **lst, int num)
{
	t_lst	*new;
	t_lst	*current;
 
	new = malloc(1 * sizeof(t_lst));
	if (new == NULL)
		exit(-1);
	new->n = num;
	new->index = 0;
	new->next = NULL;
	if(!*lst)
		*lst = new;
	current = *lst;
	while (current->next != NULL) 
		current = current->next;
	current->next = new;
}

t_lst	*ft_addfront(t_lst **lst, int n) 
{
    t_lst	*new ;

	new = malloc(sizeof(t_lst));
    if (new == NULL)
        exit(-1);
    new->n = n;
    new->index = 0;
    new->next = *lst;
    *lst = new;
	return (*lst);
}