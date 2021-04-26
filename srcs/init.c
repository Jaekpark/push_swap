/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:30:29 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/26 20:17:43 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	init_node(t_node *node)
{
	node->val = 0;
	node->prev = NULL;
	node->next = NULL;
}

void	init_stack(t_stack *stack)
{
	stack->bot = NULL;
	stack->cur = NULL;
	stack->top = NULL;
}

void	init_sort(t_sort *checker)
{
	checker->a = NULL;
	checker->b = NULL;
	checker->pivot = NULL;
	checker->size = 0;
	checker->min = 0;
	checker->max = 0;
	checker->inst_cnt = 0;
}

void	clear_node(t_node *node)
{
	node->val = 0;
	node->prev = NULL;
	node->next = NULL;
	free(node);
	node = NULL;
}