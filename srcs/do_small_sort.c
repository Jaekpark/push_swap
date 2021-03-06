/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 19:03:09 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 03:10:49 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	do_push_fast(t_sort *s, t_stack *t, t_node *n)
{
	int bot;
	int top;

	if (!s || !t || !n)
		return (-1);
	bot = idx_locate_from_bot(t, n->idx);
	top = idx_locate_from_top(t, n->idx);
	if (top == -1 && bot == -1)
		return (-1);
	else if (top == 0)
		pb(s, 1);
	else if (top >= bot)
	{
		rra(s, bot);
		pb(s, 1);
	}
	else if (top < bot)
	{
		ra(s, top);
		pb(s, 1);
	}
	return (1);
}

int			two_sort(t_sort *s, t_stack *t)
{
	if (!s || !t->top)
		return (-1);
	else if (t->top->idx > t->top->prev->idx)
		sa(s, 1);
	return (1);
}

int			three_sort(t_sort *s, t_stack *t)
{
	t_node *min;
	t_node *max;

	if (!t || !s)
		return (-1);
	min = find_min_idx_addr(t, ft_lstsize(s->a));
	max = find_max_idx_addr(t, ft_lstsize(s->a));
	if (t->top == min && t->bot != max)
	{
		rra(s, 1);
		sa(s, 1);
	}
	else if (t->top == max && t->bot == min)
	{
		sa(s, 1);
		rra(s, 1);
	}
	else if (t->top == max && t->bot != min)
		ra(s, 1);
	else if (t->top != min && t->top != max && t->bot == min)
		rra(s, 1);
	else if (t->top != min && t->top != max && t->bot == max)
		sa(s, 1);
	return (1);
}

int			four_sort(t_sort *s, t_stack *t)
{
	t_node *min;

	if (!s || !t || ft_lstsize(t) != 4)
		return (-1);
	min = find_min_idx_addr(t, ft_lstsize(s->a));
	if (!(do_push_fast(s, t, min)))
		return (-1);
	if (three_sort(s, t) == 1)
		pa(s, 1);
	return (-1);
}

int			five_sort(t_sort *s, t_stack *t)
{
	t_node *min;
	t_node *max;

	if (!s || !t || ft_lstsize(t) != 5)
		return (-1);
	min = find_min_idx_addr(t, 5);
	max = find_max_idx_addr(t, 5);
	if (!(do_push_fast(s, t, min)))
		return (-1);
	if (!(do_push_fast(s, t, max)))
		return (-1);
	if (three_sort(s, t) == 1)
	{
		pa(s, 1);
		ra(s, 1);
		pa(s, 1);
	}
	return (-1);
}
