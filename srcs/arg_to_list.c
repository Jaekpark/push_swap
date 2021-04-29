/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:27:44 by jaekpark          #+#    #+#             */
/*   Updated: 2021/04/27 17:26:14 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	 print_node(t_stack *t)
{
	t_node *tmp;

	tmp = t->bot;
	if (!t || !tmp)
		return ;
	while (1)
	{
		if (tmp->next != NULL)
			printf("%d ", tmp->val);
		if (tmp->next != NULL)
			tmp = tmp->next;
		if (tmp->next == NULL)
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
	t_node *min;
	int		idx;
	char c;

	idx = 0;
	min = NULL;
	s = malloc(sizeof(t_sort));
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	init_sort(s);
	init_stack(a);
	init_stack(b);
	s->a = a;
	s->b = b;
	arg_to_stack(argc, argv, s);
	// printf("---------\nstack a ");
	// print_node(s->a);
	// printf("---------\nstack b ");
	// print_node(s->b);
	// printf("--------\n");
	// printf("---------\nstack a ");
	// print_node(s->a);
	// printf("---------\nstack b ");
	// print_node(s->b);
	// printf("--------\n");
	c = 'f';
	printf("start\n");
	while (1)
	{
		scanf("%c", &c);
		printf("command = %c\n", c);
		if (c == 'a')
		{
			a_to_b(s);
			printf("---a_to_b---\n");
			printf("stack a ");
			print_node(s->a);
			printf("stack b ");
			print_node(s->b);
		}
		else if (c == 'b')
		{
			b_to_a(s);
			printf("---b_to_a---\n");
			printf("stack a ");
			print_node(s->a);
			printf("stack b ");
			print_node(s->b);
		}
		else if (c == 'e')
			exit(0);
		printf("calc count = %d\n", s->inst_cnt);
	}
	
	return (0);
}