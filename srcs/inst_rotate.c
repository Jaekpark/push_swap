/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:44:28 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 01:37:50 by jaekpark         ###   ########.fr       */
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
		if (s->is_checker == 1 && s->v_flag == 1)
		{
			system("clear");
			ft_printf("Exec : ra\n");
			if (s->c_flag == 1)
				print_two_stack_color(s, "ra\n");
			else
				print_two_stack(s);
		}
		if (s->is_checker == 0)
			write(STDOUT, "ra\n", 3);
		s->inst_cnt++;
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
		if (s->is_checker == 1 && s->v_flag == 1)
		{
			system("clear");
			ft_printf("Exec : rb\n");
			if (s->c_flag == 1)
				print_two_stack_color(s, "rb\n");
			else
				print_two_stack(s);
		}
		if (s->is_checker == 0)
			write(STDOUT, "rb\n", 3);
		s->inst_cnt++;
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
		if (s->is_checker == 1 && s->v_flag == 1)
		{
			system("clear");
			ft_printf("Exec : rr\n");
			if (s->c_flag == 1)
				print_two_stack_color(s, "rr\n");
			else
				print_two_stack(s);
		}
		if (s->is_checker == 0)
			write(STDOUT, "rr\n", 3);
		s->inst_cnt++;
		cnt--;
	}
	return (1);
}
