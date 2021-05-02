/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:44:28 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/01 19:45:51 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ra(t_sort *s, int cnt)
{
	if (!s || cnt <= 0)
		return (-1);
	while (cnt)
	{
		rotate(s->a);
		if (s->is_checker == 0)
		{
			s->inst_cnt++;
			write(STDOUT, "ra\n", 3);
		}
		cnt--;
	}
	return (1);
}

int		rb(t_sort *s, int cnt)
{
	if (!s || cnt <= 0)
		return (-1);
	while (cnt)
	{
		rotate(s->b);
		if (s->is_checker == 0)
		{
			s->inst_cnt++;
			write(STDOUT, "rb\n", 3);
		}
		cnt--;
	}
    return (1);
}

int		rr(t_sort *s, int cnt)
{
	if (!s || cnt <= 0)
		return (-1);
	while (cnt)
	{
		rotate(s->a);
		rotate(s->b);
		if (s->is_checker == 0)
		{
			s->inst_cnt++;
			write(STDOUT, "rr\n", 3);
		}
		cnt--;
	}
	return (1);
}
