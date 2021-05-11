/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:50:03 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 01:20:27 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		del(t_stack *t)
{
	t_node	*del_tmp;
	t_node	*new_top;

	if (!t || !t->top)
		return (-1);
	if (t->bot == t->top)
	{
		clear_node(t->top);
		t->bot = NULL;
		t->top = NULL;
		t->cur = NULL;
		return (0);
	}
	else
	{
		del_tmp = t->top;
		new_top = del_tmp->prev;
		new_top->next = NULL;
		t->top = new_top;
		clear_node(del_tmp);
	}
	return (1);
}

int		push(t_node *node, t_stack *t)
{
	t_node	*new;

	if (!t || !node)
		return (-1);
	if (!(new = malloc(sizeof(t_node))))
		return (-1);
	init_node(new);
	new->val = node->val;
	new->idx = node->idx;
	new->is_sorted = node->is_sorted;
	t->cur = new;
	if (t->cur != NULL && (t->bot == NULL && t->top == NULL))
	{
		t->bot = t->cur;
		t->top = t->cur;
	}
	else
	{
		t->top->next = t->cur;
		t->cur->prev = t->top;
		t->top = t->cur;
	}
	return (1);
}
