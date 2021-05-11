/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:23:16 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/09 22:53:59 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_update(t_sort *s)
{
	if (!s)
		return ;
	markup_sorted(s->a);
	markup_sorted(s->b);
}

int		check_inst_a_bot(char *inst)
{
	if (!inst)
		return (-1);
	else if ((ft_strncmp(inst, "ra\n", 3)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "rr\n", 3)) == 0)
		return (1);
	return (-1);
}

int		check_inst_b_bot(char *inst)
{
	if (!inst)
		return (-1);
	else if ((ft_strncmp(inst, "rb\n", 3)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "rr\n", 3)) == 0)
		return (1);
	return (-1);
}

int		check_inst_a_top(char *inst)
{
	if (!inst)
		return (-1);
	else if ((ft_strncmp(inst, "rra\n", 4)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "pa\n", 3)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "sa\n", 3)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "rrr\n", 4)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "ss\n", 3)) == 0)
		return (1);
	return (-1);
}

int		check_inst_b_top(char *inst)
{
	if (!inst)
		return (-1);
	else if ((ft_strncmp(inst, "rrb\n", 4)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "pb\n", 3)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "sb\n", 3)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "rrr\n", 4)) == 0)
		return (1);
	else if ((ft_strncmp(inst, "ss\n", 3)) == 0)
		return (1);
	return (-1);
}
