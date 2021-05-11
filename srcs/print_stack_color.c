/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:43:13 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 14:17:11 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_print_color(t_sort *s, t_node *a, t_node *b, char *inst)
{
	if (!s)
		return ;
	print_stack_a_color(s, a, inst);
	print_stack_b_color(s, b, inst);
}

void		print_stack_a_color(t_sort *s, t_node *a, char *inst)
{
	if (a != NULL && a == s->a->top)
		print_node_a_top(a, inst);
	else if (a != NULL && a != s->a->bot)
		print_node_a_mid(a);
	else if (a != NULL && a == s->a->bot)
		print_node_a_bot(a, inst);
	else if (a == NULL)
		ft_printf(BLUE"| {      } (      ) [      ] |"RESET);
}

void		print_stack_b_color(t_sort *s, t_node *b, char *inst)
{
	if (b != NULL && b == s->b->top)
		print_node_b_top(b, inst);
	else if (b != NULL && b != s->b->bot)
		print_node_b_mid(b);
	else if (b != NULL && b == s->b->bot)
		print_node_b_bot(b, inst);
	else if (b == NULL)
		ft_printf(MAGENTA" | {      } (      ) [      ] |"RESET"\n");
}

int			print_two_stack_color(t_sort *s, char *inst)
{
	t_node *a_tmp;
	t_node *b_tmp;

	a_tmp = s->a->top;
	b_tmp = s->b->top;
	if (!s)
		return (-1);
	print_header_color();
	while (1)
	{
		do_update(s);
		if (a_tmp == NULL && b_tmp == NULL)
			return (print_last_color(s));
		do_print_color(s, a_tmp, b_tmp, inst);
		if (a_tmp != NULL && a_tmp->prev != NULL)
			a_tmp = a_tmp->prev;
		else if (a_tmp != NULL && a_tmp->prev == NULL)
			a_tmp = NULL;
		if (b_tmp != NULL && b_tmp->prev != NULL)
			b_tmp = b_tmp->prev;
		else if (b_tmp != NULL && b_tmp->prev == NULL)
			b_tmp = NULL;
	}
}
