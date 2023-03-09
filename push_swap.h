/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:46:54 by clacaill          #+#    #+#             */
/*   Updated: 2023/03/09 17:00:05 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define N_MAX 2147483647
# define N_MIN -2147483648

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"

/* ************************************************************************** */
/* List */
/* ************************************************************************** */
typedef struct s_lst
{
	int				n;
	unsigned int	position;
	size_t			index;
	struct s_lst	*previous;
	struct s_lst	*next;
}	t_lst;

/* ************************************************************************** */
/* Main stack */
/* ************************************************************************** */
typedef struct s_stack
{
	size_t	size_g;
	int		key_nmbr;
	int		min;
	int		max;
	t_lst	*a;
	size_t	a_size;
	t_lst	*b;
	size_t	b_size;
}	t_stack;

/* ************************************************************************** */
/* boolean */
/* ************************************************************************** */
enum	e_select_print
{
	noprint = 0,
	print = 1
};

enum	e_lst_select
{
	a = 0,
	b = 1
};

/* ************************************************************************** */
/* Functions */
/* ************************************************************************** */
void	ft_update_index(t_lst **lst);
size_t	lst_len(t_lst *lst);
void	set_position(t_lst **lst);
/* ************************************************************************** */
/*  utils */
/* ************************************************************************** */
/* ************************************************************************** */
/*  add_lst.c */
/* ************************************************************************** */
void	ft_addback(t_lst **lst, int num);
void	addprevious(t_lst **lst);
t_lst	*ft_addfront(t_lst **lst, int n);
/* ************************************************************************** */
/*  init.c */
/* ************************************************************************** */
size_t	set_size(t_lst *lst);
int		find_min_lst(t_lst *lst);
int		find_max_lst(t_lst *lst);
int		find_key_nmbr(t_stack *stack);
/* ************************************************************************** */
/*  init_2.c */
/* ************************************************************************** */
t_stack	*init_stack(t_lst **lst);
t_lst	*init_lst(int argc, const char **argv);
/* ************************************************************************** */
/*  utils_stack.c */
/* ************************************************************************** */
void	ft_swap(t_lst **lst);
void	ft_push(t_lst **orig, t_lst **dest);
void	ft_rotate(t_lst **lst);
void	ft_reverse_rotate(t_lst **lst);
/* ************************************************************************** */
/*  checker.c */
/* ************************************************************************** */
int		is_digit(int c);
int		check_two(const int argc, const char **argv);
int		stack_checker(const int argc, const char **argv);
int		ft_already_order(const char **argv);
/* ************************************************************************** */
/* process */
/* ************************************************************************** */
/* ************************************************************************** */
/*  process_big.c */
/* ************************************************************************** */
int		ft_rotate_or_reverse(t_stack **stack, t_lst	**lst, unsigned int j);
int		ft_rotate_or_reverse2(t_lst	**lst, unsigned int j);
void	ft_reduce_a_first(t_stack **stack);
void	ft_reduce_a_min(t_stack **stack, unsigned int j);
void	ft_reduce_a_last(t_stack **stack);
/* ************************************************************************** */
/* process_big_two.c */
/* ************************************************************************** */
void	ft_reduce_a(t_stack **stack);
void	ft_fill_a_mini(t_stack **stack);
void	ft_fill_a(t_stack **stack);
/* ************************************************************************** */
/* process_three.c */
/* ************************************************************************** */
void	ft_process_three_two(t_stack **stack);
void	ft_process_three(t_stack **stack);
void	ft_process_three_reverse_two(t_stack **stack);
void	ft_process_three_reverse(t_stack **stack);
/* ************************************************************************** */
/* process_four.c */
/* ************************************************************************** */
void	ft_process_sm_four_two(t_stack **stack);
void	ft_process_sm_four(t_stack **stack);
void	ft_process_four(t_stack **stack);
/* ************************************************************************** */
/* process_five.c */
/* ************************************************************************** */
void	ft_process_sm_five_two(t_stack **stack);
void	ft_process_sm_five(t_stack **stack);
void	ft_process_five(t_stack **stack);
/* ************************************************************************** */
/* process_six.c */
/* ************************************************************************** */
void	ft_process_sm_six_two(t_stack **stack);
void	ft_process_sm_six(t_stack **stack);
void	ft_process_six(t_stack **stack);
/* ************************************************************************** */
/* process.c */
/* ************************************************************************** */
void	ft_process_big(t_stack **stack);
void	ft_process(t_stack **stack);
/* ************************************************************************** */
/* Free.c */
/* ************************************************************************** */
void	free_lst(t_lst **first);
void	*free_stack(t_stack **stack);

#endif
