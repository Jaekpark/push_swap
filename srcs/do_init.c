/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:30:29 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/02 18:51:07 by jaekpark         ###   ########.fr       */
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

void	init_sort(t_sort *s)
{
    s->a = NULL;
    s->b = NULL;
    s->size = 0;
	s->is_checker = 0;
    s->inst_cnt = 0;
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
	min = find_max_value_addr(t);
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
