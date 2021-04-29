/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:13:50 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/27 17:26:43 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_node		*find_min_address(t_stack *t)
{
	t_node *min;
	t_node *tmp;

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
	if (s->a->bot != NULL)
		s->pivot = s->a->bot;
	while (1)
	{
		if (s->pivot->val < s->a->top->val)
			pb(s);
		else if (s->pivot->val > s->a->top->val)
			ra(s);
		if (s->a->top == s->pivot)
			break ;
	}
	return (1);
}

int		check_b(t_sort *s)
{
	if (s->b->bot != NULL)
		s->pivot = s->b->bot;
	while (1)
	{
		if (s->pivot->val < s->b->top->val)
			rb(s);
		else if (s->pivot->val > s->b->top->val)
			pa(s);
		else if (s->b->top == s->pivot && ft_lstsize(s->b) != 1)
			break ;
		else if (ft_lstsize(s->b) == 1)
		{
			pa(s);
			break ;
		}
		
	}
	return (1);
}

int divide_b(t_sort *s)
{
	if (s->b->bot != NULL)
		s->pivot = s->b->bot;
	while (1)
	{
		
		if (s->pivot->val < s->b->top->val)
			pa(s);
		else if (s->pivot->val > s->b->top->val)
			rb(s);
		if (s->b->top == s->pivot)
			break ;
	}
	return (1);	
}

int		b_to_a(t_sort *s)
{
	int idx;
	int size;
	int cnt;

	idx = 0;
	cnt = 0;
	size = ft_lstsize(s->b);
	if (s->b->bot != NULL)
		s->pivot = s->a->bot;
	else 
		return (0);
	while (idx < size)
	{
		if (s->b->top->val > s->pivot->val)
		{
			rb(s);
			cnt++;
		}
		else
		{
			pa(s);
		}
		idx++;
	}
	while (cnt)
	{
		rrb(s);
		cnt--;
	}
	return (1);
}

int		a_to_b(t_sort *s)
{
	int idx;
	int size;
	int cnt;

	idx = 0;
	cnt = 0;
	size = ft_lstsize(s->a);
	if (s->a->bot != NULL)
		s->pivot = s->a->bot;
	else 
		return (0);
	while (idx < size)
	{
		if (s->a->top->val > s->pivot->val)
		{
			ra(s);
			cnt++;
		}
		else
		{
			pb(s);
		}
		idx++;
	}
	while (cnt)
	{
		rra(s);
		cnt--;
	}
	return (1);
}

int		node_idx_from_bot(t_stack *t, t_node *node)
{
	t_node *tmp;
	int idx;

	idx = 0;
	tmp = t->bot;
	while (tmp != NULL)
	{
		if (tmp == node)
			break ;
		tmp = tmp->next;
		idx++;
	}
	return (idx);
}

int		node_idx_from_top(t_stack *t, t_node *node)
{
	t_node *tmp;
	int idx;

	idx = 0;
	tmp = t->top;
	while (tmp != NULL)
	{
		if (tmp == node)
			break ;
		tmp = tmp->prev;
		idx++;
	}
	return (idx);
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
			ra(s);
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