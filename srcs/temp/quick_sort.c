/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:02:46 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/01 18:00:04 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		divide(t_sort *s, int range)
{
	int bot;
	int	top;
	t_node *min;

	min = find_min_value_addr(s->a);
	bot = locate_from_bot(s->a, range);
	top = locate_from_top(s->a, range);
	if (s->a->bot == NULL)
		return (-1);
	if (bot == -1 && top == -1)
		return (0);
	else if (top == 0)
		pb(s, 1);
	else if (top >= 0 && top < bot)
	{
		ra(s, top);
		pb(s, 1);
	}
	else if (bot >= 1 && top > bot)
	{
		rra(s, bot);
		pb(s, 1);
	}
	else if (top >= 0 && bot == top)
	{
		ra(s, top);
		pb(s, 1);
	}
	return (divide(s, range));
}

int		conquer(t_sort *s)
{
	t_node *max;
	int bot;
	int top;

	if (s->b->bot == NULL)
		return (-1);
	max = find_max_value_addr(s->b);
	bot = node_locate_from_bot(s->b, max);
	top = node_locate_from_top(s->b, max);

	if (bot == -1 && top == -1)
		return (0);
	else if (top == 0)
		pa(s, 1);
	else if (top > bot && bot >= 0)
	{
		rrb(s, bot);
		pa(s, 1);
	}
	else if (bot > top && top >= 0)
	{
		rb(s, top);
		pa(s, 1);
	}
	else if (bot >= 0 && bot == top)
	{
		rb(s, bot);
		pa(s, 1);
	}
	return (conquer(s));
}
