/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_small_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 19:03:09 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/07 22:58:17 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		two_sort_b(t_sort *s, t_stack *t)
{
	if (!s || !t)
		return (-1);
	else if (ft_lstsize(t) < 2)
		return (-1);
	else if (t->top->idx < t->top->prev->idx)
		sb(s, 1);
	return (1);
}

int		do_three_sort_b(t_sort *s, t_stack *t)
{
	if (!s || !t || !t->top)
		return (-1);
	else if (ft_lstsize(t) == 3)
		return (three_sort_b(s, t));
	else if (ft_lstsize(t) > 3)
	{
		if (t->top->idx > t->top->prev->idx && t->top->prev->idx < t->top->prev->prev->idx)
		{
			if (t->top->idx > t->top->prev->prev->idx)
			{
				rb(s, 1);
				sb(s, 1);
				rrb(s, 1);
			}
			else if (t->top->idx < t->top->prev->prev->idx)
			{
				rb(s, 1);
				sb(s, 1);
				rrb(s, 1);
				sb(s, 1);
			}
		}
		else if (t->top->idx < t->top->prev->idx)
		{
			if (t->top->idx > t->top->prev->prev->idx)
				sb(s, 1);
			else if (t->top->idx < t->top->prev->prev->idx)
			{
				if (t->top->prev->idx < t->top->prev->prev->idx)
				{
					sb(s, 1);
					rb(s, 1);
					sb(s, 1);
					rrb(s, 1);
					sb(s, 1);
				}
				else if (t->top->prev->idx > t->top->prev->prev->idx)
				{
					sb(s, 1);
					rb(s, 1);
					sb(s, 1);
					rrb(s, 1);
				}
			}
		}
	}
	return (1);
}

int		three_sort_b(t_sort *s, t_stack *t)
{
	t_node *min;
	t_node *max;

	if (!t || !s || ft_lstsize(t) < 3)
		return (-1);
	min = find_min_idx_addr(t, 3);
	max = find_max_idx_addr(t, 3);
	if (t->top == min)
	{
		if(t->top->prev->prev != max)
			rrb(s, 2);
		else
		{
			sb(s, 1);
			rrb(s, 1);
		}
	}
	else if (t->top == max)
	{
		if (t->top->prev->prev != min)
		{
			rrb(s, 1);
			sb(s, 1);
		}
	}
	else if (t->top != min && t->top != max)
	{
		if (t->top->prev->prev == min)
			sb(s, 1);
		else if (t->top->prev->prev == max)
			rrb(s, 1);
	}
	return (1);
}

int		four_sort_b(t_sort *s, t_stack *t)
{
	t_node *max;
	
	if (!s || !t || ft_lstsize(t) != 4)
		return (-1);
	max = find_max_idx_addr(t, 4);
	if (!(do_push_fast_b(s, t, max)))
		return (-1);
	if (three_sort_b(s, t) == 1)
		pb(s, 1);
	return (-1);
}

int		five_sort_b(t_sort *s, t_stack *t)
{
	t_node *min;
	t_node *max;

	if (!s || !t || ft_lstsize(t) != 5)
		return (-1);
	min = find_min_idx_addr(t, 5);
	max = find_max_idx_addr(t, 5);
	if (!(do_push_fast_b(s, t, max)))
		return (-1);
	if (!(do_push_fast_b(s, t, min)))
		return (-1);
	if (three_sort_b(s, t) == 1)
	{
		pb(s, 1);
		rb(s, 1);
		pb(s, 1);
	}
	return (-1);
}

int		do_push_fast_b(t_sort *s, t_stack *t, t_node *n)
{
	int bot;
	int top;

	if (!s || !t)
		return (-1);
	bot = idx_locate_from_bot(t, n->idx);
	top = idx_locate_from_top(t, n->idx);
	if (top == -1 && bot == -1)
		return (-1);
	else if (top == 0)
		pa(s, 1);
	else if (top >= bot)
	{
		rrb(s, bot);
		pa(s, 1);
		rb(s, bot);
	}
	else if (top < bot)
	{
		rb(s, top);
		pa(s, 1);
		rrb(s, top);
	}
	return (1);
}

int		do_push_fast(t_sort *s, t_stack *t, int pivot)
{
	int bot;
	int top;

	if (!s || !t)
		return (-1);
	bot = locate_from_bot(t, pivot);
	top = locate_from_top(t, pivot);
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
	if (s->b->top->idx < pivot / 2)
		rb(s, 1); 
	return (1);
}

int		do_three_sort_a(t_sort *s, t_stack *a)
{
	if (!s || !a || !a->top)
		return (-1);
	else if (ft_lstsize(a) == 3)
		return (three_sort_a(s, a));
	else if (ft_lstsize(a) > 3)
	{
		if (a->top->idx < a->top->prev->idx)
		{
			if (a->top->idx < a->top->prev->prev->idx && a->top->prev->idx > a->top->prev->prev->idx)
			{
				ra(s, 1);
				sa(s, 1);
				rra(s, 1);
			}
			else if (a->top->idx > a->top->prev->prev->idx)
			{
				ra(s, 1);
				sa(s, 1);
				rra(s, 1);
				sa(s, 1);
			}
		}
		else
		{
			if (a->top->idx < a->top->prev->prev->idx)
				sa(s, 1);
			else if (a->top->prev->idx > a->top->prev->prev->idx)
			{
				sa(s, 1);
				ra(s, 1);
				sa(s, 1);
				rra(s, 1);
				sa(s, 1);
			}
			else if (a->top->prev->idx < a->top->prev->prev->idx)
			{
				sa(s, 1);
				ra(s, 1);
				sa(s, 1);
				rra(s, 1);
			}
		}
	}
	return (0);
}