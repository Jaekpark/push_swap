/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:27:36 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/08 18:02:01 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clear_node(t_node *node)
{
    node->prev = NULL;
    node->next = NULL;
    free(node);
    node = NULL;
}

void	clear_stack(t_stack *t)
{
	t_node *del_tmp;

	if (!t)
		return ;
	while (t->bot != NULL)
	{
		del_tmp = t->bot;
		t->bot = t->bot->next;
		clear_node(del_tmp);
		if (t->bot == NULL)
			break ;
		else
			t->bot->prev = NULL;
	}
	t->bot = NULL;
	t->cur = NULL;
	t->top = NULL;
	free(t);
	t = NULL;
}

void	clear_sort(t_sort *s)
{
	if (!s)
		return ;
	if (s->path != NULL)
		ft_free_single((void *)s->path);
	if (s->argv != NULL)
		ft_free_single((void *)s->argv);
	if (s->num != NULL)
		ft_free_double((void **)s->num);
	clear_stack(s->a);
	clear_stack(s->b);
	free(s);
	s = NULL;
}
