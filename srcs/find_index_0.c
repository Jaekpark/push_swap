/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:25:37 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/02 20:06:03 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		idx_locate_from_bot(t_stack *t, int idx)
{
	t_node	*tmp;
	int		find;
	int		i;

	if (!t || idx < 0 || ft_lstsize(t) < 1)
		return (-1);
	tmp = t->bot;
	find = 0;
	i = 1;
	while (tmp != NULL)
	{
		if (tmp->idx == idx)
		{
			find = 1;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	if (find == 1)
		return (i);
	return (-1);

}

int		idx_locate_from_top(t_stack *t, int idx)
{
	t_node	*tmp;
	int		find;
	int		i;

	if (!t || idx < 0 || ft_lstsize(t) < 1)
		return (-1);
	tmp = t->top;
	find = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->idx == idx)
		{
			find = 1;
			break ;
		}
		tmp = tmp->prev;
		i++;
	}
	if (find == 1)
		return (i);
	return (-1);
}

int		val_locate_from_bot(t_stack *t, int val)
{
	t_node	*tmp;
	int		find;
	int		idx;

	idx = 1;
	find = 0;
	tmp = t->bot;
	while (tmp != NULL)
	{
		if (tmp->val == val)
		{
			find = 1;
			break ;
		}
		tmp = tmp->next;
		idx++;
	}
	if (find == 1)
		return (idx);
	return (-1);
}

int		val_locate_from_top(t_stack *t, int val)
{
	t_node	*tmp;
	int		find;
	int		idx;

	idx = 0;
	find = 0;
	tmp = t->top;
	while (tmp != NULL)
	{
		if (tmp->val == val)
		{
			find = 1;
			break ;
		}
		tmp = tmp->prev;
		idx++;
	}
	if (find == 1)
		return (idx);
	return (-1);
}
