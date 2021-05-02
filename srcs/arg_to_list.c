/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:27:44 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/02 20:54:42 by jaekpark         ###   ########.fr       */
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

void	 print_node(t_stack *t)
{
    t_node *tmp;

    tmp = t->top;
	printf("\n");
    if (!t || !tmp)
        return ;
    while (1)
    {
        if (tmp->prev != NULL)
            printf("|<%3d> (%3d) [%3d]|\n", tmp->val, tmp->idx, tmp->is_sorted);
        if (tmp->prev != NULL)
            tmp = tmp->prev;
        if (tmp->prev == NULL)
        {
            printf("|<%3d> (%3d) [%3d]|\n", tmp->val, tmp->idx, tmp->is_sorted);
			printf("-------------------\n");
			break ;
        }
    }
}

void	print_two_stack(t_sort *s)
{
	t_node *a_tmp;
	t_node *b_tmp;

	a_tmp = s->a->top;
	b_tmp = s->b->top;
	printf("\n");
	printf("      stack a	          stack b\n\n");
	if (!s)
		return ;
	while (1)
	{
		if (a_tmp != NULL && a_tmp->prev != NULL)
		{
			printf("|<%3d> (%3d) [%3d]| ", a_tmp->val, a_tmp->idx, a_tmp->is_sorted);
			a_tmp = a_tmp->prev;
		}
		else if (a_tmp == NULL)
			printf("|#################| ");
		else if (a_tmp != NULL && a_tmp->prev == NULL)
		{
			printf("|<%3d> (%3d) [%3d]| ", a_tmp->val, a_tmp->idx, a_tmp->is_sorted);
			a_tmp = NULL;
		}
		if (b_tmp != NULL && b_tmp->prev != NULL)
		{
			printf("|<%3d> (%3d) [%3d]|\n", b_tmp->val, b_tmp->idx, b_tmp->is_sorted);
			b_tmp = b_tmp->prev;
		}
		else if (b_tmp == NULL)
			printf("|#################|\n");
		else if (b_tmp != NULL && b_tmp->prev == NULL)
		{
			printf("|<%3d> (%3d) [%3d]|\n", b_tmp->val, b_tmp->idx, b_tmp->is_sorted);
			b_tmp = NULL;
		}
		if (a_tmp == NULL && b_tmp == NULL)
		{
			printf("--------------------------------------\n");
			break ;
		}
	}
}

int		arg_to_stack(int argc, char **argv, t_sort *s)
{
    int	i;
    int	val;

    i = argc;
    val = 0;
    if (argc < 2 || !argv)
        return (-1);
    while (--i >= 1)
        push_arg(ft_atoi(argv[i]), s->a);
    s->size = argc - 1;
    return (1);
}