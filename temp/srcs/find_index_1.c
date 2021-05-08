/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:01:00 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/05 01:27:59 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		locate_from_bot(t_stack *t, int pivot)
{
	t_node	*tmp;
	int		find;
	int		i;

	i = 1;
	find = 0;
	tmp = t->bot;
	while (tmp != NULL)
	{
		if (tmp->idx <= pivot)
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

int		locate_from_top(t_stack *t, int pivot)
{
	t_node	*tmp;
	int		i;
	int		find;

	find = 0;
	i = 0;
	tmp = t->top;
	while (tmp != NULL)
	{
		if (tmp->idx <= pivot)
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

int		node_locate_from_bot(t_stack *t, t_node *node)
{
	t_node	*tmp;
	int		i;

	i = 1;
	tmp = t->bot;
	while (tmp != NULL)
	{
		if (tmp == node)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int		node_locate_from_top(t_stack *t, t_node *node)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = t->top;
	while (tmp != NULL)
	{
		if (tmp == node)
			break ;
		tmp = tmp->prev;
		i++;
	}
	return (i);
}
