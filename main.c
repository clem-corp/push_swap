/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:35:36 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/16 12:38:37 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* A mettre dans ./utils/stack.c */

/* Fin de mettre dans ./utils/stack.c*/

int	main(int argc, const char **argv)
{
	t_stack	*stack;
	t_lst	*lst;

	if (argc < 2)
		return (ft_printf("Error\n"));
	else
	{
		/* la ya tout a gerer  */
		if (stack_checker((const int)argc, (const char **)argv) == 0)
			return (ft_printf("Error\n"));
		if (already_order(argv) == 1)
			return (ft_printf(""));
		lst = init_lst(argc, argv);
		stack = init_stack(&lst);
		// stack->a = lst;
		// algo(&stack);
		//free_stack(&stack);
	}
	return (ft_printf("SUCCESS 2.0\n"));
}
