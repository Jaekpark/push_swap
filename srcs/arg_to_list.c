/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:27:44 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/07 20:49:36 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		push_arg(int val, t_stack *dest)
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

int		arg_to_stack(int argc, char **argv, t_sort *s)
{
    int	i;
    int	val;

    i = argc;
    val = 0;
    if (argc < 2 || !argv || !s)
        return (-1);
    while (--i >= 1)
        push_arg(ft_atoi(argv[i]), s->a);
    return (1);
}