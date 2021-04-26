/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:13:50 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/26 22:31:04 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		ret_min_max(t_stack *target, int *x, int *y)
{
	t_node *tmp;
	int min;
	int max;

	min = target->top->val;
	max = target->top->val;
	tmp = target->bot;
	while (tmp->next != NULL)
	{
		if (tmp->val < min)
			min = tmp->val;
		else if (tmp->val > max)
			max = tmp->val;
		tmp = tmp->next;
	}
	*x = min;
	*y = max;
}

void		set_min_max(t_sort *s)
{
	t_node *tmp;
	int min;
	int max;

	min = s->a->top->val;
	max = s->a->top->val;
	tmp = s->a->bot;
	while (tmp->next != NULL)
	{
		if (tmp->val < min)
			min = tmp->val;
		else if (tmp->val > max)
			max = tmp->val;
		tmp = tmp->next;
	}
	s->min = min;
	s->max = max;
}

int		three_sort(t_sort *s, t_stack *target)
{
	int min;
	int max;
	t_stack *tmp;

	tmp = target;
	min = 0;
	max = 0;
	ret_min_max(target, &min, &max);
	if (min == tmp->bot->val && max == tmp->top->val)
		return (0);
	else if (min == tmp->bot->val && max != tmp->top->val)
		sa(s);
	else if (max == tmp->bot->val)
	{
		if (min == tmp->top->val)
		{
			ra(s);
			sa(s);
		}
		else
			rra(s);
	}
	else
	{
		if (min == tmp->top->val)
			ra(s);
		else
		{
			sa(s);
			ra(s);
		}
	}
	return (1);
}

int		divide(t_sort *s)
{
	s->pivot = s->a->bot;
	while (1)
	{
		
		if (s->pivot->val > s->a->top->val)
			pb(s);
		else if (s->pivot->val < s->a->top->val)
			rra(s);
		if (s->a->top == s->pivot)
			break ;
	}
	return (1);
}

int		divide_1(t_sort *s)
{
	int i;
	int pivot;

	i = 0;
	pivot = s->a->top->val;
	while (i < s->size)
	{
		if (pivot >= s->a->top->val)
			pb(s);
		else if (pivot < s->a->top->val)
			rra(s);
		i++;
	}
	return (1);
}
/*
1 2 3 a < b < c ok
1 3 2  a < b > c sa => 1 2 3

2 3 1  a < b > c ra => 1 2 3
2 1 3 a > b < c => sa => 2 3 1 ra 3 2 1

3 1 2 a > b < c rra 1 2 3
3 2 1 a > b > c ra 1 3 2 sa 1 2 3
*/