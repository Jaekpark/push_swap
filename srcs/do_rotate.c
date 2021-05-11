/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:56:15 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 01:20:54 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		r_rotate(t_stack *t)
{
	t_node	*top_tmp;
	t_node	*bot_tmp;

	if (!t->bot || !t->bot->next || t->top == t->bot)
		return (-1);
	else
	{
		top_tmp = t->top;
		bot_tmp = t->bot;
		t->bot = bot_tmp->next;
		t->bot->prev = NULL;
		t->top->next = bot_tmp;
		bot_tmp->prev = t->top;
		t->top = bot_tmp;
		t->top->next = NULL;
	}
	return (1);
}

int		rotate(t_stack *t)
{
	t_node	*top_tmp;

	if (!t->top || t->top == t->bot)
		return (-1);
	else
	{
		top_tmp = t->top;
		t->top = top_tmp->prev;
		t->top->next = NULL;
		t->bot->prev = top_tmp;
		top_tmp->next = t->bot;
		top_tmp->prev = NULL;
		t->bot = top_tmp;
	}
	return (1);
}
