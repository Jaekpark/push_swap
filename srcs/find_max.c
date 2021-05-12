/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:35:26 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/12 22:50:12 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_max_idx_addr(t_stack *t, int size)
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

t_node	*find_max_value_addr(t_stack *t, int size)
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

t_node	*find_sec_addr(t_stack *t, t_node *max, int size)
{
	int		i;
	t_node	*tmp;
	t_node	*ret;

	i = 0;
	tmp = t->bot;
	ret = NULL;
	while (tmp != NULL && i < size)
	{
		if (max->idx - 1 == tmp->idx)
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}
