/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:51:38 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/27 12:34:26 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sa(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "sa\n", 3);
	return (swap(s->a));
}

int		sb(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "sb\n", 3);
	return (swap(s->b));
}

int		ss(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "ss\n", 3);
	return (swap(s->a) && swap(s->b));
}

int		pa(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "pa\n", 3);
	return (push(s->b->top->val, s->a) && del(s->b));
}

int		pb(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "pb\n", 3);
	return (push(s->a->top->val, s->b) && del(s->a));
}

int		ra(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "ra\n", 3);
	return (rotate(s->a));
}

int		rb(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "rb\n", 3);
	return (rotate(s->b));
}

int		rr(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "rr\n", 3);
	return (rotate(s->a) && rotate(s->b));
}

int		rra(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "rra\n", 4);
	return (r_rotate(s->a));
}

int		rrb(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "rrb\n", 4);
	return (r_rotate(s->b));
}

int		rrr(t_sort *s)
{
	s->inst_cnt++;
	write(STDOUT, "rrr\n", 4);
	return (r_rotate(s->a) && r_rotate(s->b));
}