/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:31:04 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/01 19:38:04 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sa(t_sort *s, int cnt)
{
	if (cnt <= 0 || !s || !s->a || ft_lstsize(s->a) <= 1)
		return (-1);
	while (cnt)
	{
		swap(s->a);
		if (s->is_checker == 0)
		{	
			s->inst_cnt++;
			write(STDOUT, "sa\n", 3);
		}
		cnt--;
	}
    return (1);
}

int		sb(t_sort *s, int cnt)
{
	if (cnt <= 0 || !s || !s->b || ft_lstsize(s->b) <= 1)
		return (-1);
	while (cnt)
	{
		swap(s->b);

		if (s->is_checker == 0)
		{
			s->inst_cnt++;
			write(STDOUT, "sa\n", 3);
		}
		cnt--;
	}
	return (1);
}

int		ss(t_sort *s, int cnt)
{
	if (cnt <= 0 || !s || (!s->a && !s->b))
		return (-1);
	while (cnt)
	{
		swap(s->a);
		swap(s->b);
		if (s->is_checker == 0)
		{
			s->inst_cnt++;
			write(STDOUT, "ss\n", 3);
		}
		cnt--;
	}
    return (1);
}
