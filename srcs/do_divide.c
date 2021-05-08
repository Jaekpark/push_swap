/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:05:42 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/08 21:44:23 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int		check_size_and_sort_a(t_sort *s, int size)
{
	if (!s || !s->a->top)
		return (-1);
	if (size == 1)
		return (1);
	if (size == 2)
		two_sort_a(s, s->a);
	else if (size == 3)
		three_sort_a(s, s->a);
	else if (size == 4)
		four_sort_a(s, s->a);
	else if (size == 5)
		five_sort_a(s, s->a);
	return (1);
}

int		check_break_condition(t_sort *s, int pivot)
{
	t_node *tmp;

	if (!s || !s->a->top || pivot < 0)
		return (-1);
	tmp = s->a->top;
	while (tmp != NULL)
	{
		if (tmp->idx >= s->p1)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

int		do_divide(t_sort *s, int size)
{
	if (!s || !s->a || !s->b || size < 0)
		return (-1);
	while (0 < size--)
	{
		if (check_break_condition(s, s->p1) == 1)
			return (0);
		else if (s->a->top->idx >= s->p1)
			ra(s, 1);
		else
		{
			pb(s, 1);
			if (ft_lstsize(s->b) > 1 && s->b->top->idx < s->p2)
			{
				if (s->a->top->idx >= s->p1)
				{
					rr(s, 1);
					size--;
				}
				else
					rb(s, 1);
			}
		}
	}
	return (1);
}

int		divide_t(t_sort *s, int size)
{
	if (!s || !s->a || !s->a->top)
		return (-1);
	if (markup_sorted(s->a) == 1)
		return (1);
	if (size <= 3 || ft_lstsize(s->a) <= 3)
		return (check_size_and_sort_a(s, size));
	if (!(set_pivot(s, s->a, size)))
		return (-1);
	do_divide(s, size);
	divide_t(s, ft_lstsize(s->a));
	return (1);
}

int		do_conquer(t_sort *s)
{
	t_node	*max;
	t_node	*min;
	int		min_cnt;
	int		max_cnt;
	int		rrac;

	rrac = 0;
	if (!(max = find_max_idx_addr(s->b, ft_lstsize(s->b))))
		return (0);
	if (!(min = find_min_idx_addr(s->b, ft_lstsize(s->b))))
		return (0);
	max_cnt = calc_cnt_max(s, max);
	min_cnt = calc_cnt_min(s, min);
	if (max_cnt == 0 && min_cnt == 0)
		return (0);
	if (max_cnt < 5 + min_cnt)
		conquer_by_max(s, max);
	else if (max_cnt > 5 + min_cnt)
		rrac += conquer_by_min(s, min);
	else if (max_cnt == min_cnt)
		conquer_by_max(s, max);
	else
		conquer_by_max(s, max);
	return (rrac);
}

int		conquer_t(t_sort *s)
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
