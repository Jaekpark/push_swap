/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:17:37 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/07 21:04:41 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libs/includes/ft_printf.h"

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"
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
    t_stack		*a;
    t_stack		*b;
	int			p1;
	int			p2;
	int			is_checker;
    long long	inst_cnt;
}				t_sort;

//print_error.c
int		print_status(int status);
int		set_pivot(t_sort *s, t_stack *t, int size);
int		check_size_and_sort_a(t_sort *s, int size);

int		check_arg_isnum(char **argv);
int		check_arg_isdup(char **argv);

void	set_sort_for_pw(t_sort *s, t_stack *a, t_stack *b);
void	set_sort_for_ck(t_sort *s, t_stack *a, t_stack *b);

//three_sort.c
int		do_three_sort_a(t_sort *s, t_stack *a);
int 	two_sort_a(t_sort *s, t_stack *t);
int		three_sort_a(t_sort *s, t_stack *t);
int		four_sort_a(t_sort *s, t_stack *t);
int		five_sort_a(t_sort *s, t_stack *t);
int		do_push_fast_a(t_sort *s, t_stack *t, t_node *n);
int		do_push_fast_b(t_sort *s, t_stack *t, t_node *n);
int		do_push_fast(t_sort *s, t_stack *t, int pivot);

//three_sort_b.c
int		do_three_sort_b(t_sort *s, t_stack *t);
int 	two_sort_b(t_sort *s, t_stack *t);
int		three_sort_b(t_sort *s, t_stack *t);
int		four_sort_b(t_sort *s, t_stack *t);
int		five_sort_b(t_sort *s, t_stack *t);

//art_to_list.c
int		push_arg(int val, t_stack *dest);
int		arg_to_stack(int argc, char **argv, t_sort *s);

//uitls.c
int		markup_sorted(t_stack *t);
void	do_update(t_sort *s);
int		is_sorted(t_stack *t);

//find_index.c
int		idx_locate_from_bot(t_stack *t, int idx);
int		idx_locate_from_top(t_stack *t, int idx);
int		val_locate_from_bot(t_stack *t, int val);
int		val_locate_from_top(t_stack *t, int val);
int		locate_from_bot(t_stack *t, int pivot);
int		locate_from_top(t_stack *t, int pivot);
int		node_locate_from_bot(t_stack *t, t_node *node);
int		node_locate_from_top(t_stack *t, t_node *node);

//find_min_max.c
t_node	*find_min_idx_addr(t_stack *t, int size);
t_node	*find_max_idx_addr(t_stack *t, int size);
t_node	*find_min_value_addr(t_stack *t, int size);
t_node	*find_max_value_addr(t_stack *t, int size);

//do_init.c
int		init_node_index(t_stack *t, int idx);
void	init_node(t_node *node);
void	init_stack(t_stack *t);
int		init_sort(t_sort *s, char *name);
t_node	*make_new_node(int val);
void	init_sort_cnt_div(t_sort *s);


//ft_inst.c
int		del(t_stack *target);
int		push(t_node *node, t_stack *dest);
int		swap(t_stack *target);
int		rotate(t_stack *target);
int		r_rotate(t_stack *target);

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
int		print_two_stack(t_sort *s);
void	reset_index(t_stack *t);
int		divide_t(t_sort *s, int size);
int		conquer_temp(t_sort *s, int size);
int		conquer_t(t_sort *s);
int		conquer_by_max(t_sort *s, t_node *max);
int		conquer_by_min(t_sort *s, t_node *min);
int		calc_cnt_min(t_sort *s, t_node *min);
int		calc_cnt_max(t_sort *s, t_node *max);
#endif
