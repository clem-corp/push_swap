/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:25:17 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 15:29:28 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_lst **lst)
{
	t_lst	*temp;

	if (!(*lst) || (*lst)->next == NULL)
		return ;
	temp = (*lst);
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
	(*lst)->previous = NULL;
	temp->previous = *lst;
	set_position(lst);
	return ;
}

void	ft_push(t_lst **orig, t_lst **dest)
{
	t_lst	*temp;

	if (!*orig)
		return ;
	temp = *orig;
	(*orig) = (*orig)->next;
	if ((*orig) != NULL)
		(*orig)->previous = NULL;
	temp->next = *dest;
	if (*dest)
		(*dest)->previous = temp;
	else
		temp->previous = NULL;
	*dest = temp;
	if (*orig)
		set_position(orig);
	if (*dest)
		set_position(dest);
	return ;
}

void	ft_rotate(t_lst **lst)
{
	t_lst	*temp;

	if (!*lst)
		return ;
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	if (*lst != temp)
	{
		temp->next = *lst;
		(*lst)->previous = temp;
		temp = *lst;
		*lst = (*lst)->next;
		temp->next = NULL;
		(*lst)->previous = NULL;
	}
	set_position(lst);
	return ;
}

void	ft_reverse_rotate(t_lst **lst)
{
	t_lst	*temp;

	if (!*lst)
		return ;
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	if (*lst != temp)
	{
		temp->next = *lst;
		temp->previous->next = NULL;
		temp->previous = NULL;
		(*lst)->previous = temp;
		(*lst) = temp;
	}
	set_position(lst);
	return ;
}
