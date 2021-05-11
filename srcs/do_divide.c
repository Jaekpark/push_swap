/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:05:42 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/11 16:31:27 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_break_condition(t_sort *s, int pivot)
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

static int	do_divide(t_sort *s, int size)
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

int			check_size_and_sort(t_sort *s, int size)
{
	if (!s || !s->a->top)
		return (-1);
	if (size == 1)
		return (1);
	if (is_sorted(s) == 1)
		return (1);
	if (size == 2)
		two_sort(s, s->a);
	else if (size == 3)
		three_sort(s, s->a);
	else if (size == 4)
		four_sort(s, s->a);
	else if (size == 5)
		five_sort(s, s->a);
	return (1);
}

int			divide_t(t_sort *s, int size)
{
	if (!s || !s->a || !s->a->top)
		return (-1);
	if (markup_sorted(s->a) == 1)
		return (1);
	if (size <= 3 || ft_lstsize(s->a) <= 3)
		return (check_size_and_sort(s, size));
	if (!(set_pivot(s, s->a, size)))
		return (-1);
	do_divide(s, size);
	divide_t(s, ft_lstsize(s->a));
	return (1);
}
