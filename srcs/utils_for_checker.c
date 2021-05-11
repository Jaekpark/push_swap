/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 02:20:10 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 02:20:28 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_push_or_swap(char *line)
{
	if (!line)
		return (-1);
	else if ((ft_strncmp(line, "pa", 3)) == 0)
		return (PA);
	else if ((ft_strncmp(line, "pb", 3)) == 0)
		return (PB);
	else if ((ft_strncmp(line, "sa", 3)) == 0)
		return (SA);
	else if ((ft_strncmp(line, "sb", 3)) == 0)
		return (SB);
	else if ((ft_strncmp(line, "ss", 3)) == 0)
		return (SS);
	return (-1);
}

int		is_rotate(char *line)
{
	if (!line)
		return (-1);
	else if ((ft_strncmp(line, "ra", 3)) == 0)
		return (RA);
	else if ((ft_strncmp(line, "rb", 3)) == 0)
		return (RB);
	else if ((ft_strncmp(line, "rr", 3)) == 0)
		return (RR);
	else if ((ft_strncmp(line, "rra", 4)) == 0)
		return (RRA);
	else if ((ft_strncmp(line, "rrb", 4)) == 0)
		return (RRB);
	else if ((ft_strncmp(line, "rrr", 4)) == 0)
		return (RRR);
	return (-1);
}

int		check_instruction(char *line)
{
	int ret;

	ret = 0;
	if (!line)
		return (-1);
	else if ((ret = is_push_or_swap(line)) > 0)
		return (ret);
	else if ((ret = is_rotate(line)) > 0)
		return (ret);
	return (-1);
}

int		excute_instruction(t_sort *s, int inst)
{
	if (!s || inst < 0)
		return (-1);
	else if (inst == PA)
		pa(s, 1);
	else if (inst == PB)
		pb(s, 1);
	else if (inst == SA)
		sa(s, 1);
	else if (inst == SB)
		sb(s, 1);
	else if (inst == RA)
		ra(s, 1);
	else if (inst == RB)
		rb(s, 1);
	else if (inst == RR)
		rr(s, 1);
	else if (inst == RRA)
		rra(s, 1);
	else if (inst == RRB)
		rrb(s, 1);
	else if (inst == RRR)
		rrr(s, 1);
	return (1);
}

int		instruction_error(char *line)
{
	if (line != NULL)
		free(line);
	return (-1);
}
