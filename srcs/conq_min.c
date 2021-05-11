/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conq_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:40:50 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 15:53:37 by jaekpark         ###   ########.fr       */
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
	ra(s, 1);
	if (s->a->top->idx == s->a->top->prev->idx + 1)
		sa(s, 1);
	return (1);
}

int			calc_cnt_min(t_sort *s, t_node *min)
{
	int bot;
	int top;
	int cnt;

	cnt = 0;
	if (s->b->top == NULL)
		return (0);
	bot = idx_locate_from_bot(s->b, min->idx);
	top = idx_locate_from_top(s->b, min->idx);
	if (bot == -1 && top == -1)
		return (0);
	else if (top == 0)
		cnt += 3;
	else if (bot == 1)
		cnt += 4;
	else if (bot == top)
		cnt += top + 3;
	else if (bot > top && top > 0)
		cnt += top + 3;
	else if (top > bot && bot > 0)
		cnt += bot + 3;
	return (cnt);
}

int			conquer_by_min(t_sort *s, t_node *min)
{
	int	bot;
	int	top;
	int	rac;

	rac = 0;
	if (!s || !min || !s->b->top)
		return (0);
	bot = idx_locate_from_bot(s->b, min->idx);
	top = idx_locate_from_top(s->b, min->idx);
	if (bot == -1 && top == -1)
		return (0);
	if (top == 0)
		rac += push_for_conquer(s, top, 1);
	else if (bot == 1)
		rac += push_for_conquer(s, bot, 0);
	else if (bot == top)
		rac += push_for_conquer(s, top, 1);
	else if (bot > top && top > 0)
		rac += push_for_conquer(s, top, 1);
	else if (top > bot && bot > 0)
		rac += push_for_conquer(s, bot, 0);
	return (rac);
}
