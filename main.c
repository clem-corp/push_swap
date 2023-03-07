/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:35:36 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/07 19:25:44 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void update_index(t_lst **lst) {
    t_lst *curr = *lst;
    while (curr != NULL) {
        int count = 0;
        t_lst *iter = *lst;
        while (iter != NULL) {
            if (iter->n < curr->n)
                count++;
            iter = iter->next;
        }
        curr->index = count;
        curr = curr->next;
    }
	return;
}

int	main(int argc, const char **argv)
{
	t_stack	*stack;
	t_lst	*lst;

	if (argc < 2)
		return (ft_printf("Error\n"));
	else
	{
		if (stack_checker((const int)argc, (const char **)argv) == 0)
			return (ft_printf("Error\n"));
		if (already_order(argv) == 1)
			return (ft_printf("OK"));
		lst = init_lst(argc, argv);
		if(!lst)
			return (ft_printf("Error\n"));
		stack = init_stack(&lst);
		if(!stack)
			return (ft_printf("Error\n"));
		update_index(&(stack->a));
		ft_process(&stack);
/* 		while(stack->a)
		{
			printf("stack->a->n : %d \n", stack->a->n);
			stack->a = stack->a->next;
		} */
		free_stack(&stack);
	}
}
