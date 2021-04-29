/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:50:03 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/27 16:16:01 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node *make_new_node(int val)
{
	t_node *new;

	if (!(new = malloc(sizeof(t_node))))
		return (NULL);
	init_node(new);
	new->val = val;
	return (new);
}

int		del(t_stack *target)
{
	t_node *del_tmp;
	t_node *new_top;

	if (target->bot == target->top)
	{
		clear_node(target->top);
		target->bot = NULL;
		target->top = NULL;
		target->cur = NULL;
		return (0);
	}
	else
	{
		del_tmp = target->top;
		new_top = del_tmp->prev;
		new_top->next = NULL;
		target->top = new_top;
	}
	return (1);
}

int		push(int val, t_stack *dest)
{
	t_node *new;
	if (!dest)
		return (-1);
	if (!(new = malloc(sizeof(t_node))))
		return (-1);
	init_node(new);
	new->val = val;
	dest->cur = new;
	if (dest->cur != NULL && (dest->bot == NULL && dest->top == NULL))
	{
		dest->bot = dest->cur;
		dest->top = dest->cur;
	}
	else
	{
		dest->top->next = dest->cur;
		dest->cur->prev = dest->top;
		dest->top = dest->cur;
	}
	return (1);
}

int		swap(t_stack *target)
{
	int tmp;

	tmp = 0;
	if (!target->bot)
		return (-1);
	if (!target->bot->next)
		return (0);
	tmp = target->top->val;
	target->top->val = target->top->prev->val;
	target->top->prev->val = tmp;
	return (1);
}

int		r_rotate(t_stack *target)
{
	t_node *top_tmp;
	t_node *bot_tmp;

	if (!target->bot || !target->bot->next || target->top == target->bot)
		return (-1);
	else
	{
		top_tmp = target->top;
		bot_tmp = target->bot;

		target->bot = bot_tmp->next;
		target->bot->prev = NULL;
		target->top->next = bot_tmp;
		bot_tmp->prev = target->top;
		target->top = bot_tmp;
		target->top->next = NULL;
	}
	return (1);
}

int		rotate(t_stack *target)
{
	t_node *top_tmp;
	t_node *bot_tmp;

	if (!target->top || target->top == target->bot)
		return (-1);
	else
	{
		top_tmp = target->top;
		bot_tmp = target->bot;

		target->top = top_tmp->prev;
		target->top->next = NULL;

		target->bot->prev = top_tmp;
		top_tmp->next = target->bot;
		top_tmp->prev = NULL;
		target->bot = top_tmp;
	}
	return (1);
}