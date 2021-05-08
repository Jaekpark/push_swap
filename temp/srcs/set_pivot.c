/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:21:46 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/07 18:02:07 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_pivot_small_size(t_sort *s, int idx, int size)
{
	if (!s || size < 0)
		return (-1);
	if (size <= 30)
	{
		s->p1 = (double)idx - ((size / 3) * 1);
		s->p2 = (double)idx - ((size / 3) * 2);
	}
	else if (size <= 50)
	{
		s->p1 = (double)idx - (size / 5) * 3;
		s->p2 = (double)idx - (size / 5) * 4;
	}
	else if (size <= 70)
	{
		s->p1 = (double)idx - (size / 7) * 5;
		s->p2 = (double)idx - (size / 7) * 6;
	}
	else
	{
		s->p1 = (double)idx - (size / 10) * 7;
		s->p2 = (double)idx - (size / 10) * 8;
	}
	return (1);
}

static int	set_pivot_big_size(t_sort *s, int idx, int size)
{
	if (!s || size < 0)
		return (-1);	
	if (size <= 100)
	{
		s->p1 = (double)idx - (size / 10) * 7;
		s->p2 = (double)idx - (size / 10) * 8;
	}
	else if (size <= 300)
	{
		s->p1 = (double)idx - (size / 10) * 8;
		s->p2 = (double)idx - (size / 10) * 9;
	}
	else if (size <= 400)
	{
		s->p1 = (double)idx - (size / 11) * 9;
		s->p2 = (double)idx - (size / 11) * 10;
	}
	return (1);
}

int			set_pivot(t_sort *s, t_stack *t, int size)
{
	t_node	*max;

	if (!s || !t->top || size < 3 || ft_lstsize(t) < 3)
		return (-1);
	if (!(max = find_max_idx_addr(t, size)))
		return (-1);
	if (size < 100)
		return (set_pivot_small_size(s, max->idx, size));
	else if (size <= 400)
		return (set_pivot_big_size(s, max->idx, size));
	else
	{
		s->p1 = (double)max->idx - (size / 12) * 10;
		s->p2 = (double)max->idx - (size / 12) * 11;
	}
	return (1);
}