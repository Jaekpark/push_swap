/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:04:07 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/01 20:04:29 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node		*find_min_idx_addr(t_stack *t)
{
	t_node	*min;
	t_node	*tmp;

	if (!t || ft_lstsize(t) < 1)
		return (NULL);
	tmp = t->bot;
	min = t->bot;
	while (tmp != NULL)
	{
		if (min->idx > tmp->idx)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_node		*find_min_value_addr(t_stack *t)
{
	t_node	*min;
	t_node	*tmp;

	if (!t)
		return (NULL);
	tmp = t->bot;
	min = t->bot;
	while (tmp != NULL)
	{
		if (min->val > tmp->val)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
