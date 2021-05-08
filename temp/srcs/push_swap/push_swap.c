/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:59:57 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/07 21:42:22 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_sort	*s;

	if (argc <= 1 || !argv)
		return (print_status(ERR));
	else if (!(s = malloc(sizeof(t_sort))))
		return (print_status(ERR));
	else if (!(init_sort(s, argv[1])))
		return (print_status(ERR));
	else if (!(check_arg_isnum(argv)))
		return (print_status(ERR));
	else if (!(check_arg_isdup(argv)))
		return (print_status(ERR));
	else if (!(arg_to_stack(argc, argv, s)))
		return (print_status(ERR));
	else if (!(init_node_index(s->a, 0)))
		return (print_status(ERR));
	else if (!(check_size_and_sort_a(s, ft_lstsize(s->a))))
		return (print_status(ERR));
	else if (!(divide_t(s, ft_lstsize(s->a))))
		return (print_status(ERR));
	else if (!(conquer_t(s)))
		return (print_status(ERR));
	printf("\x1b[32m""Hello I'm green""\x1b[0m""\n");
	print_two_stack(s);
	printf("inst cnt = %lld\n", s->inst_cnt);
	return (0);
}

