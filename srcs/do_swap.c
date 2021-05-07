/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:53:34 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/06 21:15:44 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		swap(t_stack *t)
{
	if (!t || ft_lstsize(t) < 2)
		return (-1);
    int	tmp;
	int tmp_idx;

    tmp = 0;
	tmp_idx = -1;
    if (!t->bot)
        return (-1);
    if (!t->bot->next)
        return (0);
    tmp = t->top->val;
	tmp_idx = t->top->idx;
    t->top->val = t->top->prev->val;
	t->top->idx = t->top->prev->idx;
	t->top->is_sorted = -1;
    t->top->prev->val = tmp;
	t->top->prev->idx = tmp_idx;
	t->top->prev->is_sorted = -1;
    return (1);
}
