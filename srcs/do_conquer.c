/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conquer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:19:27 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 17:03:33 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	compare_cnt_a(t_sort *s)
{
	if (s->v.sec_cnt != -1 && s->v.sec_cnt + 1 < s->v.max_cnt)
		conquer_by_max(s, s->v.sec);
	else
		conquer_by_max(s, s->v.max);
	return (0);
}

static int	compare_cnt_b(t_sort *s)
{
	int rrac;

	rrac = 0;
	if (s->v.sec_cnt != -1 && s->v.sec_cnt + 1 < s->v.min_cnt)
		conquer_by_max(s, s->v.sec);
	else
		rrac += conquer_by_min(s, s->v.min);
	return (rrac);
}

static int	compare_cnt_c(t_sort *s)
{
	if (s->v.sec_cnt != -1 && s->v.sec_cnt + 1 < s->v.max_cnt)
		conquer_by_max(s, s->v.sec);
	else
		conquer_by_max(s, s->v.max);
	return (0);
}

static int	do_conquer(t_sort *s)
{
	int		rrac;

	rrac = 0;
	init_val(&(s->v));
	if (!(s->v.max = find_max_idx_addr(s->b, ft_lstsize(s->b))))
		return (0);
	if (!(s->v.min = find_min_idx_addr(s->b, ft_lstsize(s->b))))
		return (0);
	s->v.sec = find_sec_addr(s->b, s->v.max, ft_lstsize(s->b));
	if (s->v.sec != NULL)
		s->v.sec_cnt = calc_cnt_max(s, s->v.sec);
	s->v.max_cnt = calc_cnt_max(s, s->v.max);
	s->v.min_cnt = calc_cnt_min(s, s->v.min);
	if (s->v.max_cnt == 0 && s->v.min_cnt == 0)
		return (0);
	if (s->v.max_cnt < s->v.min_cnt)
		compare_cnt_a(s);
	else if (s->v.max_cnt > s->v.min_cnt)
		rrac += compare_cnt_b(s);
	else if (s->v.max_cnt == s->v.min_cnt)
		compare_cnt_c(s);
	else
		conquer_by_max(s, s->v.max);
	return (rrac);
}

int			conquer_t(t_sort *s)
{
	int i;
	int rrac;

	i = 0;
	rrac = 0;
	if (!s || !s->b || !s->b->top)
		return (-1);
	while (1)
	{
		if (ft_lstsize(s->b) <= 0)
			break ;
		rrac += do_conquer(s);
	}
	rra(s, rrac);
	return (1);
}
