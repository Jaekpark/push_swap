/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:31:04 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/08 22:16:16 by jaekpark         ###   ########.fr       */
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
		if (s->is_checker == 0 && s->v_flag == 1)
		{	
			ft_printf("Exec : ");
		}
		if (s->is_checker == 0)
			write(STDOUT, "sa\n", 3);
		if (s->v_flag == 1)
			print_two_stack(s);
		s->inst_cnt++;
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
		if (s->is_checker == 0 && s->v_flag == 1)
		{	
			ft_printf("Exec : ");
		}
		if (s->is_checker == 0)
			write(STDOUT, "sa\n", 3);
		if (s->v_flag == 1)
			print_two_stack(s);
		s->inst_cnt++;
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
		if (s->is_checker == 0 && s->v_flag == 1)
		{	
			ft_printf("Exec : ");
		}
		if (s->is_checker == 0)
			write(STDOUT, "ss\n", 3);
		if (s->v_flag == 1)
			print_two_stack(s);
		s->inst_cnt++;
		cnt--;
	}
    return (1);
}
