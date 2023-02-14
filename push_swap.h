/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:46:54 by clacaill          #+#    #+#             */
/*   Updated: 2023/02/14 17:44:23 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
/* # include "../libft/libft/libft.h" */

/* ************************************************************************** */
/* List */
/* ************************************************************************** */
typedef struct s_lst
{
	int				n;
	size_t			index;
	struct s_lst	*previous;
	struct s_lst	*next;
}	t_lst;

/* ************************************************************************** */
/* Main stack */
/* ************************************************************************** */
typedef struct s_stack
{
	// global size
	size_t	g_count;
	// Liste a
	t_lst	*a;
	size_t	a_size;
	int		a_min;
	int		a_max;
	// Liste b
	t_lst	*b;
	size_t	b_size;
	int		b_min;
	int		b_max;
}	t_stack;


/* ************************************************************************** */
/* boolean */
/* ************************************************************************** */
enum	select_print
{
	print,
	noprint
};

enum	stack_select
{
	a,
	b
};

#endif