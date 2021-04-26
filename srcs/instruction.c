/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:51:38 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/26 17:56:37 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		sa(t_sort *s)
{
	s->inst_cnt++;
	return (swap(s->a));
}

int		sb(t_sort *s)
{
	s->inst_cnt++;
	return (swap(s->b));
}

int		ss(t_sort *s)
{
	s->inst_cnt++;
	return (swap(s->a) && swap(s->b));
}

int		pa(t_sort *s)
{
	s->inst_cnt++;
	return (push(s->b->top->val, s->a) && del(s->b));
}

int		pb(t_sort *s)
{
	s->inst_cnt++;
	return (push(s->a->top->val, s->b) && del(s->a));
}

int		ra(t_sort *s)
{
	s->inst_cnt++;
	return (rotate(s->a));
}

int		rb(t_sort *s)
{
	s->inst_cnt++;
	return (rotate(s->b));
}

int		rr(t_sort *s)
{
	s->inst_cnt++;
	return (rotate(s->a) && rotate(s->b));
}

int		rra(t_sort *s)
{
	s->inst_cnt++;
	return (r_rotate(s->a));
}

int		rrb(t_sort *s)
{
	return (r_rotate(s->b));
}

int		rrr(t_sort *s)
{
	return (r_rotate(s->a) && r_rotate(s->b));
}