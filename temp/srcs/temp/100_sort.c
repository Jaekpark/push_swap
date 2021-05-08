#include "../includes/push_swap.h"

int		divide_first(t_sort *s, int p, int e)
{
	int i = 0;
	int size = ft_lstsize(s->a);
	
	if (!s || !s->a || !s->b)
		return (-1);
	while (i < size)
	{
		if (s->a->top->val <= e && s->a->top->val >= p)
		{	
			pb(s, 1);
			if (ft_lstsize(s->b) > 1 && s->b->top->val < e / 2)
			{
				if (s->a->top->val > e)
					rr(s, 1);
				else
					rb(s, 1);
			}
		}
		else
			ra(s, 1);
		i++;
	}
	return (1);
}

int divide_second(t_sort *s, t_stack *a, t_stack *b, int pivot)
{
	int i = 0;
	int size = ft_lstsize(a);
	int p1 = pivot;

	if (!a || !b)
		return (-1);
	while (i < size)
	{
		if (a->top->val < p1)
		{
			pb(s, 1);
		}
		else
			ra(s, 1);
		i++;
	}
	while (a->bot)
	{
		pb(s, 1);
	}
	return (1);
}

int	conquer_to_b(t_sort *s)
{
	t_node *min;
	int bot;
	int top;

	if (s->a->bot == NULL)
		return (-1);
	min = find_min_value_addr(s->a);
	bot = node_locate_from_bot(s->a, min);
	top = node_locate_from_top(s->a, min);
	if (bot == -1 && top == -1)
		return (0);
	else if (top == 0)
		pb(s, 1);
	else if (top > bot && bot >= 0)
	{
		rra(s, bot);
		pb(s, 1);
	}
	else if (bot > top && top >= 0)
	{
		ra(s, top);
		pb(s, 1);
	}
	else if (bot >= 0 && bot == top)
	{
		rra(s, bot);
		pb(s, 1);
	}
	return (conquer_to_b(s));
}