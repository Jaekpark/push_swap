/* ************************************************************************** */
/*                                                                            */
/*    	                                                :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:40:36 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/29 20:42:43 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node		*find_less_max_idx_addr(t_stack *t, t_node *m, int size)
{
	int		i;
	t_node	*ret;
	t_node	*tmp;

	i = 0;
	if (!t || !m || ft_lstsize(t) < 1)
		return (NULL);
	tmp = t->top;
	ret = NULL;
	while (tmp != NULL && i < size)
	{
		if (tmp->idx == m->idx - 1)
			ret = tmp;
			break ;
		tmp = tmp->prev;
		i++;
	}
	return (ret);
}

t_node		*find_max_idx_addr(t_stack *t, int size)
{
	int		i;
	t_node	*max;
	t_node	*tmp;

	i = 0;
	if (!t || ft_lstsize(t) < 1)
		return (NULL);
	tmp = t->top;
	max = t->top;
	while (tmp != NULL && i < size)
	{
		if (max->idx <= tmp->idx)
			max = tmp;
		tmp = tmp->prev;
		i++;
	}
	return (max);
}

t_node		*find_max_value_addr(t_stack *t, int size)
{
	int		i;
	t_node	*max;
	t_node	*tmp;

	i = 0;
	if (!t)
		return (NULL);
	tmp = t->bot;
	max = t->bot;
	while (tmp != NULL && i < size)
	{
		if (max->val <= tmp->val)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

