/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:27:44 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/26 22:29:26 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	 print_node(t_stack *t)
{
	t_node *tmp;

	tmp = t->top;
	if (!t || !tmp)
		return ;
	while (1)
	{
		if (tmp->prev != NULL)
			printf("%d\n", tmp->val);
		if (tmp->prev != NULL)
			tmp = tmp->prev;
		if (tmp->prev == NULL)
		{
			printf("%d\n", tmp->val);
			break ;	
		}
	}
}

int		arg_to_stack(int argc, char **argv, t_sort *s)
{
	int	i;
	int	val;

	i = 0;
	val = 0;
	if (argc < 2 || !argv)
		return (-1);
	while (++i < argc)
		push(ft_atoi(argv[i]), s->a);
	s->size = i - 1;
	return (1);
}

int		main(int argc, char **argv)
{
	t_sort	*s;
	t_stack *a;
	t_stack *b;

	s = malloc(sizeof(t_sort));
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	init_sort(s);
	init_stack(a);
	init_stack(b);
	s->a = a;
	s->b = b;
	arg_to_stack(argc, argv, s);
	printf("----\nstack a\ntop\n-\n");
	print_node(s->a);
	printf("-\nbot\n----\n");
	printf("----\nafter sort stack a\ntop\n-\n");
	divide_1(s);
	print_node(s->a);
	printf("-\nbot\n----\n");
	print_node(s->b);
	printf("calc cnt = %d\n", s->inst_cnt);
	return (0);
}