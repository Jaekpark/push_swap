/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:53:34 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/02 19:45:03 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		swap(t_stack *t)
{
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
    t->top->prev->val = tmp;
	t->top->prev->idx = tmp_idx;
    return (1);
}
