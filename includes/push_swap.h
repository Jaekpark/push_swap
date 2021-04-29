/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:17:37 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/27 17:19:56 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define STDERR 2
# define STDOUT 1
# define STDIN 0


typedef struct	s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node *bot;
	t_node *cur;
	t_node *top;
}				t_stack;

typedef struct s_sort
{
	t_stack	*a;
	t_stack	*b;
	t_node	*pivot;
	int		size;
	int		min;
	int		max;
	int		inst_cnt;
}				t_sort;

void	set_min_max(t_sort *s);
void	ret_min_max(t_stack *target, int *x, int *y);
int		three_sort(t_sort *s, t_stack *target);
int		divide(t_sort *s);
int		divide_1(t_sort *s);
int		check_b(t_sort *s);

int		node_idx_from_top(t_stack *t, t_node *node);
int		node_idx_from_bot(t_stack *t, t_node *node);

int		a_to_b(t_sort *s);
int		b_to_a(t_sort *s);
int		divide_b(t_sort *s);

t_node *find_min_address(t_stack *t);

void	init_node(t_node *node);
void	init_stack(t_stack *stack);
void	init_sort(t_sort *checker);

t_node	*make_new_node(int val);
int		del(t_stack *target);
int		push(int val, t_stack *dest);
int		swap(t_stack *target);
int		rotate(t_stack *target);
int		r_rotate(t_stack *target);

int 	ft_lstsize(t_stack *t);
int		sa(t_sort *s);
int		sb(t_sort *s);
int		ss(t_sort *s);
int		pa(t_sort *s);
int		pb(t_sort *s);
int		ra(t_sort *s);
int		rb(t_sort *s);
int		rr(t_sort *s);
int		rra(t_sort *s);
int		rrb(t_sort *s);
int		rrr(t_sort *s);

void	clear_node(t_node *node);
int		arg_to_stack(int argc, char **argv, t_sort *s);

int		ft_atoi(const char *str);

#endif