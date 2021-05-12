/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:25:37 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/13 04:40:02 by parkjaekw        ###   ########.fr       */
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
