/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:30:29 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 16:46:03 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_val(t_val *v)
{
	if (!v)
		return ;
	v->max = NULL;
	v->min = NULL;
	v->sec = NULL;
	v->max_cnt = -1;
	v->sec_cnt = -1;
	v->min_cnt = -1;
}

void	init_node(t_node *node)
{
	node->val = 0;
	node->idx = -1;
	node->is_sorted = -1;
	node->prev = NULL;
	node->next = NULL;
}

void	init_stack(t_stack *t)
{
	t->bot = NULL;
	t->cur = NULL;
	t->top = NULL;
}

int		init_sort(t_sort *s, char *name)
{
	int ret;

	ret = 0;
	if (!s)
		return (-1);
	else if (!(s->a = malloc(sizeof(t_stack))))
		return (-1);
	else if (!(s->b = malloc(sizeof(t_stack))))
		return (-1);
	if ((ret = ft_strnrcmp(name, "push_swap", 9)) == 0)
		s->is_checker = 0;
	if ((ret = ft_strnrcmp(name, "checker", 7)) == 0)
		s->is_checker = 1;
	init_stack(s->a);
	init_stack(s->b);
	s->path = NULL;
	s->num = NULL;
	s->argv = NULL;
	s->c_flag = 0;
	s->i_flag = 0;
	s->v_flag = 0;
	s->p1 = 0;
	s->p2 = 0;
	s->inst_cnt = 0;
	return (1);
}

int		init_node_index(t_stack *t, int idx)
{
	t_node	*tmp;
	t_node	*min;
	int		new_idx;
	int		not_indexing;

	if (!t || idx < 0 || idx >= ft_lstsize(t))
		return (-1);
	tmp = t->bot;
	min = find_max_value_addr(t, ft_lstsize(t));
	new_idx = idx + 1;
	not_indexing = 0;
	while (tmp != NULL)
	{
		if (tmp->idx == -1)
		{
			not_indexing++;
			if (min->val > tmp->val)
				min = tmp;
		}
		tmp = tmp->next;
	}
	if (not_indexing == 0)
		return (0);
	min->idx = idx;
	return (init_node_index(t, new_idx));
}
