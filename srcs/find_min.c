/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:04:07 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 02:40:54 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_min_idx_addr(t_stack *t, int size)
{
	int		i;
	t_node	*min;
	t_node	*tmp;

	i = 0;
	if (!t || !t->bot || !t->top || size == 0)
		return (NULL);
	tmp = t->bot;
	min = t->bot;
	while (tmp != NULL && i < size)
	{
		if (min->idx > tmp->idx)
			min = tmp;
		tmp = tmp->next;
		i++;
	}
	return (min);
}

t_node	*find_min_value_addr(t_stack *t, int size)
{
	int		i;
	t_node	*min;
	t_node	*tmp;

	i = 0;
	if (!t || !t->bot || !t->top || size == 0)
		return (NULL);
	tmp = t->bot;
	min = t->bot;
	while (tmp != NULL && i < size)
	{
		if (min->val > tmp->val)
			min = tmp;
		tmp = tmp->next;
		i++;
	}
	return (min);
}
