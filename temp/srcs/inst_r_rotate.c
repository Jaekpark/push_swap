/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_r_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:51:38 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/04 17:02:49 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rra(t_sort *s, int cnt)
{
	if (!s || cnt <= 0 || ft_lstsize(s->a) == 1)
		return (-1);
	while (cnt)
	{
		r_rotate(s->a);
		if (s->is_checker == 0)
			write(STDOUT, "rra\n", 4);
		s->inst_cnt++;
		cnt--;
	}
	return (1);
}

int		rrb(t_sort *s, int cnt)
{
	if (!s || cnt <= 0 || ft_lstsize(s->b) == 1)
		return (-1);
	while (cnt)
	{
		r_rotate(s->b);
		if (s->is_checker == 0)
			write(STDOUT, "rrb\n", 4);
		cnt--;
		s->inst_cnt++;
	}
	return (1);
}

int		rrr(t_sort *s, int cnt)
{
	if (!s || cnt <= 0 || !s->a->top || !s->b->top)
		return (-1);
	while (cnt)
	{
		r_rotate(s->a);
		r_rotate(s->b);
		if (s->is_checker == 0)
			write(STDOUT, "rrr\n", 4);
		s->inst_cnt++;
		cnt--;
	}
	return (1);
}