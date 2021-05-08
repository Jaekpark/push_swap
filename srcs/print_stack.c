/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:43:13 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/08 02:59:33 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_header(void)
{
	ft_printf(ANSI_COLOR_BLUE"|----------------------------|"ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_MAGENTA" |----------------------------|"ANSI_COLOR_RESET"\n");
	ft_printf(ANSI_COLOR_BLUE"|"ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_BLUE"          [stack a]         "ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_BLUE"|"ANSI_COLOR_RESET ANSI_COLOR_MAGENTA" |"ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_MAGENTA"          [stack b]         "ANSI_COLOR_RESET ANSI_COLOR_MAGENTA"|\n"ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_BLUE"|----------------------------|"ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_MAGENTA" |----------------------------|"ANSI_COLOR_RESET"\n");
	ft_printf(ANSI_COLOR_BLUE"| "ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_BLUE"{ data } ( indx ) [ sort ]"ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_BLUE" |"ANSI_COLOR_RESET ANSI_COLOR_MAGENTA" | "ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_MAGENTA"{ data } ( indx ) [ sort ]"ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_MAGENTA" |"ANSI_COLOR_RESET"\n");
	ft_printf(ANSI_COLOR_BLUE"|----------------------------|"ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_MAGENTA" |----------------------------|"ANSI_COLOR_RESET"\n");
}

void	print_stack_a(t_sort *s, t_node *a)
{
		if (a != NULL && a == s->a->top)
		{
			ft_printf(ANSI_COLOR_BLUE"| "ANSI_COLOR_RESET);
			ft_printf(ANSI_COLOR_YELLOW"{%6d} (%6d) [%6d]" ANSI_COLOR_RESET, a->val, a->idx, a->is_sorted);
			ft_printf(ANSI_COLOR_BLUE" |"ANSI_COLOR_RESET);
		}
		else if (a != NULL)
		{
			ft_printf(ANSI_COLOR_BLUE"| "ANSI_COLOR_RESET);
			ft_printf(ANSI_COLOR_BLUE"{%6d} (%6d) [%6d]"ANSI_COLOR_RESET, a->val, a->idx, a->is_sorted);
			ft_printf(ANSI_COLOR_BLUE" |"ANSI_COLOR_RESET);
		}
		else if (a == NULL)
			ft_printf(ANSI_COLOR_BLUE"| {      } (      ) [      ] |"ANSI_COLOR_RESET);
}

void	print_stack_b(t_sort *s, t_node *b)
{
		if (b != NULL && b == s->b->top)
			ft_printf(ANSI_COLOR_MAGENTA" | "ANSI_COLOR_RESET ANSI_COLOR_YELLOW "{%6d} (%6d) [%6d]" ANSI_COLOR_RESET ANSI_COLOR_MAGENTA" |\n"ANSI_COLOR_RESET, b->val, b->idx, b->is_sorted);
		else if (b != NULL)
			ft_printf(ANSI_COLOR_MAGENTA" | {%6d} (%6d) [%6d] |\n"ANSI_COLOR_RESET, b->val, b->idx, b->is_sorted);
		else if (b == NULL)
			ft_printf(ANSI_COLOR_MAGENTA" | {      } (      ) [      ] |"ANSI_COLOR_RESET"\n");
}

int		print_last(void)
{
	ft_printf(ANSI_COLOR_BLUE"|----------------------------|"ANSI_COLOR_RESET);
	ft_printf(ANSI_COLOR_MAGENTA" |----------------------------|"ANSI_COLOR_RESET"\n");
	return (1);
}

int		print_two_stack(t_sort *s)
{
	t_node *a_tmp;
	t_node *b_tmp;

	a_tmp = s->a->top;
	b_tmp = s->b->top;
	if (!s)
		return (-1);
	print_header();
	while (1)
	{
		if (a_tmp == NULL && b_tmp == NULL)
			return (print_last());
		print_stack_a(s, a_tmp);
		print_stack_b(s, b_tmp);
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