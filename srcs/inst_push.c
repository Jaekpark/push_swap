/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:38:20 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/05 04:28:31 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		pa(t_sort *s, int cnt)
{
	if (cnt <= 0 || !s)
		return (-1);
	while (cnt)
	{
		if (!s->b->top)
			break ;
		push(s->b->top, s->a);
		del(s->b);
		if (s->is_checker == 0)
			write(STDOUT, "pa\n", 3);
		s->inst_cnt++;
		cnt--;
	}
	return (1);
}

int		pb(t_sort *s, int cnt)
{
	if (cnt <= 0 || !s->a)
		return (-1);
	while (cnt)
	{
		if (!s->a->top)
			break ;
		push(s->a->top, s->b);
		del(s->a);
		if (s->is_checker == 0)
			write(STDOUT, "pb\n", 3);
		s->inst_cnt++;
		cnt--;
	}
	return (1);
}
