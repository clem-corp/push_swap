/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:35:36 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 17:38:56 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_index(t_lst **lst)
{
	t_lst	*curr;
	int		count;
	t_lst	*iter;

	curr = *lst;
	count = 0;
	iter = *lst;
	while (curr != NULL)
	{
		count = 0;
		iter = *lst;
		while (iter != NULL)
		{
			if (iter->n < curr->n)
				count++;
			iter = iter->next;
		}
		curr->index = count;
		curr = curr->next;
	}
	return ;
}

size_t	lst_len(t_lst *lst)
{
	size_t	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	main(int argc, const char **argv)
{
	t_stack	*stack;
	t_lst	*lst;

	if (argc < 2)
		return (0);
	else
	{
		if (stack_checker((const int)argc, (const char **)argv) == 0)
			return (ft_printf("Error\n"));
		if (argc == 2 || ft_already_order(argv) == 1)
			return (0);
		lst = init_lst(argc, argv);
		if (!lst)
			return (ft_printf("Error\n"));
		stack = init_stack(&lst);
		if (!stack)
			return (ft_printf("Error\n"));
		ft_update_index(&(stack->a));
		ft_process(&stack);
		free_stack(&stack);
	}
	return (0);
}
