/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:17:37 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/02 20:51:21 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define STDERR 2
# define STDOUT 1
# define STDIN 0
# define ERR -1
# define OK	1
# define KO 0
# define MSG_ERR "Error\n"
# define MSG_OK	"OK\n"
# define MSG_KO "KO\n"

typedef struct	s_sort
{
    t_stack	*a;
    t_stack	*b;
	int		size;
	int		is_checker;
    int		inst_cnt;
}				t_sort;

//print_error.c
int		print_status(int status);

//three_sort.c
int		three_sort(t_sort *s, t_stack *t);
int 	two_sort(t_sort *s, t_stack *t);
int		five_sort(t_sort *s, t_stack *t);
int		four_sort(t_sort *s, t_stack *t);
int		do_push_fast(t_sort *s, t_stack *t, t_node *n);

//art_to_list.c
void    print_node(t_stack *t);
int		push_arg(int val, t_stack *dest);
int		arg_to_stack(int argc, char **argv, t_sort *s);

//uitls.c
int		markup_sorted(t_stack *t);
void	do_update(t_sort *s);
int		is_sorted(t_stack *t);

int 	divide_first(t_sort *s, int p, int e);
int		divide_second(t_sort *s, t_stack *a, t_stack *b, int pivot);
int		conquer_to_b(t_sort *s);

//find_index.c
int		idx_locate_from_bot(t_stack *t, int idx);
int		idx_locate_from_top(t_stack *t, int idx);
int		val_locate_from_bot(t_stack *t, int val);
int		val_locate_from_top(t_stack *t, int val);
int		locate_from_bot(t_stack *t, int range);
int		locate_from_top(t_stack *t, int range);
int		node_locate_from_bot(t_stack *t, t_node *node);
int		node_locate_from_top(t_stack *t, t_node *node);

//find_min_max.c
t_node	*find_min_idx_addr(t_stack *t);
t_node	*find_max_idx_addr(t_stack *t);
t_node	*find_min_value_addr(t_stack *t);
t_node	*find_max_value_addr(t_stack *t);

//do_init.c
int		init_node_index(t_stack *t, int idx);
void	init_node(t_node *node);
void	init_stack(t_stack *t);
void	init_sort(t_sort *s);
t_node	*make_new_node(int val);

//ft_inst.c
int		del(t_stack *target);
int		push(t_node *node, t_stack *dest);
int		swap(t_stack *target);
int		rotate(t_stack *target);
int		r_rotate(t_stack *target);

//sort
int		compare(t_sort *s, int r);
int		divide(t_sort *s, int range);
int		conquer(t_sort *s);
int     a_to_b(t_sort *s);
int     b_to_a(t_sort *s);

//instruction.c
int		sa(t_sort *s, int cnt);
int		sb(t_sort *s, int cnt);
int		ss(t_sort *s, int cnt);
int		pa(t_sort *s, int cnt);
int		pb(t_sort *s, int cnt);
int		ra(t_sort *s, int cnt);
int		rb(t_sort *s, int cnt);
int		rr(t_sort *s, int cnt);
int		rra(t_sort *s, int cnt);
int		rrb(t_sort *s, int cnt);
int		rrr(t_sort *s, int cnt);

//clear.c
void	clear_node(t_node *node);

//divide.c
void	print_two_stack(t_sort *s);
void	reset_index(t_stack *t);
int		divide_t(t_sort *s, int size, int cnt);
#endif