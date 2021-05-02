/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:02:29 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/02 20:45:26 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reset_index(t_stack *t)
{
	t_node *tmp;

	if (!t || !t->top || !t->bot)
		return ;
	tmp = t->bot;
	while (tmp != NULL)
	{
		tmp->idx = -1;
		tmp = tmp->next;
	}
}

void	do_update(t_sort *s)
{
	if (!s)
		return ;
	markup_sorted(s->a);
	markup_sorted(s->b);
}

int		markup_sorted(t_stack *t)
{
	t_node	*tmp;

	if (ft_lstsize(t) < 1)
		return (-1);
	if (!t->top || !t || !t->bot)
		return (-1);
	tmp = t->top;
	tmp->is_sorted = 1;
	while (tmp->prev != NULL)
	{
		if (tmp->val < tmp->prev->val)
		{
			tmp->prev->is_sorted = 1;
		}
		else if (tmp->val > tmp->prev->val)
		{
			tmp->prev->is_sorted = 0;
		}
		tmp = tmp->prev;
	}
	return (1);
}

int		is_sorted(t_stack *t)
{
	int		i;
	int 	size;
	t_node	*min;
	t_node	*max;
	t_node	*tmp;
	int		cnt;

	min = find_min_idx_addr(t);
	max = find_max_idx_addr(t);
	i = min->idx;
	size = max->idx;
	cnt = ft_lstsize(t);
	tmp = t->top;
	while (i <= size)
	{
		if (tmp->idx == i)
			i++;
		else
			return (-1);
		cnt--;
		if (tmp->prev != NULL)
			tmp = tmp->prev;
		else
			break ;
	}
	if (cnt == 0)
		return (1);
	return (-1);
}