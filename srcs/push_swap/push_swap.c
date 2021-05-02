/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:59:57 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/02 20:51:49 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int main(int argc, char **argv)
{
    
        t_sort	*s;
        t_stack *a;
        t_stack *b;

		int cnt = 1;

        s = malloc(sizeof(t_sort));
        a = malloc(sizeof(t_stack));
        b = malloc(sizeof(t_stack));
        init_sort(s);
        init_stack(a);
        init_stack(b);
        s->a = a;
        s->b = b;
        arg_to_stack(argc, argv, s);
		init_node_index(s->a, 0);
		printf("@@@@@@@ before sort @@@@@@@\n");
		print_two_stack(s);
		if (ft_lstsize(s->a) == 2)
			two_sort(s, s->a);
		else if (ft_lstsize(s->a) == 3)
			three_sort(s, s->a);
		else if (ft_lstsize(s->a) == 5)
			five_sort(s, s->a);
		else
		{
			divide_t(s, ft_lstsize(s->a), cnt);
		}
		printf("&&&&&&&& after sort &&&&&&&&\n");
		print_two_stack(s);
		// printf("stack a ");
		// print_node(s->a);
		// printf("\n");
		// printf("stack b ");
		// print_node(s->b);
		// printf("\n");
		printf("inst cnt = %d\n", s->inst_cnt);

        return (0);
}