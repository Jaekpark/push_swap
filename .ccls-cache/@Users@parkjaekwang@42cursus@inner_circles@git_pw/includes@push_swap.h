/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:17:37 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 18:11:13 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libs/includes/ft_printf.h"

# define VFLAG "-v"
# define CFLAG "-c"
# define VCFLAG "-vc"
# define CVFLAG "-cv"
# define IFLAG "-I"
# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define DELAY 200000
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# define STDERR 2
# define STDOUT 1
# define STDIN 0
# define ERR -1
# define OK	1
# define KO 0
# define END 2
# define MSG_ERR "Error\n"
# define MSG_OK	"OK\n"
# define MSG_KO "KO\n"

typedef struct	s_val
{
	t_node		*max;
	t_node		*min;
	t_node		*sec;
	int			min_cnt;
	int			sec_cnt;
	int			max_cnt;
}				t_val;

typedef struct	s_sort
{
	t_stack		*a;
	t_stack		*b;
	t_val		v;
	char		*path;
	char		*argv;
	char		**num;
	int			p1;
	int			p2;
	int			is_checker;
	int			v_flag;
	int			c_flag;
	int			i_flag;
	long long	inst_cnt;
}				t_sort;

/*
**		initialize for sort
*/
void			init_node(t_node *node);
void			init_stack(t_stack *t);
int				init_sort(t_sort *s, char *name);
int				init_node_index(t_stack *t, int idx);
void			init_val(t_val *v);
/*
**		function for sort
*/
void			do_update(t_sort *s);
int				set_pivot(t_sort *s, t_stack *t, int size);
int				markup_sorted(t_stack *t);
int				is_sorted(t_sort *s);
/*
**		function for checker
*/
int				is_push_or_swap(char *line);
int				is_rotate(char *line);
int				instruction_error(char *line);
int				check_instruction(char *line);
int				excute_instruction(t_sort *s, int inst);
/*
**		validation argument
*/
int				check_arg_isdup(char **argv, int idx);
int				check_arg_type(t_sort *s, char **argv);
int				check_num_overflow(char *num);
/*
**		validation flag
*/
int				check_iflag(t_sort *s, char *path);
int				check_vcflag(t_sort *s, int index);
int				check_flag(t_sort *s, char **argv);
int				check_all_flag(t_sort *s, char *argv);
/*
**		make stack for sort
*/
t_node			*make_new_node(int val);
int				read_buffer(t_sort *s);
int				push_arg(int val, t_stack *dest);
int				split_argv(t_sort *s);
int				arr_to_stack(t_sort *s);
int				arg_to_stack(int argc, char **argv, t_sort *s);
int				make_stack(t_sort *s, int argc, char **argv);
int				read_file(t_sort *s);
/*
**		function for instruction
*/
int				del(t_stack *target);
int				push(t_node *node, t_stack *dest);
int				swap(t_stack *target);
int				rotate(t_stack *target);
int				r_rotate(t_stack *target);
/*
**		execute instruction
*/
int				sa(t_sort *s, int cnt);
int				sb(t_sort *s, int cnt);
int				ss(t_sort *s, int cnt);
int				pa(t_sort *s, int cnt);
int				pb(t_sort *s, int cnt);
int				ra(t_sort *s, int cnt);
int				rb(t_sort *s, int cnt);
int				rr(t_sort *s, int cnt);
int				rra(t_sort *s, int cnt);
int				rrb(t_sort *s, int cnt);
int				rrr(t_sort *s, int cnt);
/*
**		calculate instruction count for conquer
*/
int				calc_cnt_max(t_sort *s, t_node *max);
int				conquer_by_max(t_sort *s, t_node *max);
int				calc_cnt_min(t_sort *s, t_node *min);
int				conquer_by_min(t_sort *s, t_node *min);
/*
**		divide and conquer
*/
int				conquer_t(t_sort *s);
int				divide_t(t_sort *s, int size);
int				check_size_and_sort(t_sort *s, int size);
/*
**		function for small_sort
*/
int				two_sort(t_sort *s, t_stack *t);
int				three_sort(t_sort *s, t_stack *t);
int				four_sort(t_sort *s, t_stack *t);
int				five_sort(t_sort *s, t_stack *t);
/*
**	find location of value in stack
*/
int				idx_locate_from_bot(t_stack *t, int idx);
int				idx_locate_from_top(t_stack *t, int idx);
t_node			*find_max_idx_addr(t_stack *t, int size);
t_node			*find_max_value_addr(t_stack *t, int size);
t_node			*find_min_idx_addr(t_stack *t, int size);
t_node			*find_min_value_addr(t_stack *t, int size);
t_node			*find_sec_addr(t_stack *t, t_node *max, int size);
/*
**		function for print stack
*/
void			print_node(t_node *t);
void			print_node_yellow(t_node *t);
void			print_node_magenta(t_node *t);
void			print_node_blue(t_node *t);
void			print_node_a_top(t_node *a, char *inst);
void			print_node_a_bot(t_node *a, char *inst);
void			print_node_a_mid(t_node *a);
void			print_node_b_top(t_node *a, char *inst);
void			print_node_b_bot(t_node *a, char *inst);
void			print_node_b_mid(t_node *a);
void			print_header_color(void);
int				print_last_color(t_sort *s);
void			print_header(void);
int				print_last(t_sort *s);
void			print_stack_a_color(t_sort *s, t_node *a, char *inst);
void			print_stack_b_color(t_sort *s, t_node *b, char *inst);
int				print_two_stack_color(t_sort *s, char *inst);
int				print_two_stack(t_sort *s);
void			print_stack_b(t_node *b);
void			print_stack_a(t_node *a);
int				check_inst_a_bot(char *inst);
int				check_inst_b_bot(char *inst);
int				check_inst_a_top(char *inst);
int				check_inst_b_top(char *inst);
/*
**		memory free
*/
void			clear_node(t_node *n);
void			clear_stack(t_stack *t);
void			clear_sort(t_sort *s);
/*
**		print result and exit program.
*/
int				print_status(int status, t_sort *s);

#endif
