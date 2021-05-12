/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conq_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:40:41 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/12 22:35:06 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	push_for_conquer(t_sort *s, int cnt, int rb_flag)
{
	if (!s || !s->b || cnt < 0)
		return (0);
	if (cnt > 0)
	{
		if (rb_flag == 0)
			rrb(s, cnt);
		else if (rb_flag == 1)
			rb(s, cnt);
	}
	pa(s, 1);
	if (s->a->top->idx == s->a->top->prev->idx + 1)
		sa(s, 1);
	return (1);
}

int			calc_cnt_max(t_sort *s, t_node *max)
{
	int bot;
	int top;
	int cnt;

	cnt = 0;
	if (ft_lstsize(s->b) == 0)
		return (0);
	bot = idx_locate_from_bot(s->b, max->idx);
	top = idx_locate_from_top(s->b, max->idx);
	if (bot == -1 && top == -1)
		return (0);
	if (top == 0)
		cnt++;
	else if (bot == 1)
		cnt += 2;
	else if (bot == top)
		cnt += bot + 1;
	else if (bot > top && top > 0)
		cnt += top + 1;
	else if (top > bot && bot > 0)
		cnt += bot + 1;
	return (cnt);
}

int			conquer_by_max(t_sort *s, t_node *max)
{
	int	bot;
	int	top;

	if (!s || !max || !s->b->top)
		return (0);
	bot = idx_locate_from_bot(s->b, max->idx);
	top = idx_locate_from_top(s->b, max->idx);
	if (bot == -1 && top == -1)
		return (0);
	else if (top == 0)
		pa(s, 1);
	else if (bot == 1)
		push_for_conquer(s, bot, 0);
	else if (bot == top)
		push_for_conquer(s, top, 1);
	else if (bot > top && top > 0)
		push_for_conquer(s, top, 1);
	else if (top > bot && bot > 0)
		push_for_conquer(s, bot, 0);
	return (1);
}

