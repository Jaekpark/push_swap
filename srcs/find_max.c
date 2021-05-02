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

t_node		*find_max_idx_addr(t_stack *t)
{
	t_node	*max;
	t_node	*tmp;

	if (!t || ft_lstsize(t) < 1)
		return (NULL);
	tmp = t->bot;
	max = t->bot;
	while (tmp != NULL)
	{
		if (max->idx < tmp->idx)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_node		*find_max_value_addr(t_stack *t)
{
	t_node	*max;
	t_node	*tmp;

	if (!t)
		return (NULL);
	tmp = t->bot;
	max = t->bot;
	while (tmp != NULL)
	{
		if (max->val < tmp->val)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

