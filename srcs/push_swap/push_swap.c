/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:59:57 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/08 22:15:46 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_sort	*s;
	int 	ret;

	s = NULL;
	if (argc <= 1 || !argv || argc > 20000)
		return (print_status(ERR, s));
	else if (!(s = malloc(sizeof(t_sort))))
		return (print_status(ERR, s));
	else if ((init_sort(s, argv[0])) == -1)
		return (print_status(ERR, s));
	else if ((ret = check_arg_type(s, argv)) == -1)
		return (print_status(ERR, s));
	else if ((check_arg_isdup(argv, ret)) == -1)
		return (print_status(ERR, s));
	else if (!(make_stack(s, argc, argv)))
		return (print_status(ERR, s));
	else if (!(init_node_index(s->a, 0)))
		return (print_status(ERR, s));
	else if (!(check_size_and_sort_a(s, ft_lstsize(s->a))))
		return (print_status(ERR, s));
	else if (!(divide_t(s, ft_lstsize(s->a))))
		return (print_status(ERR, s));
	else if (!(conquer_t(s)))
		return (print_status(ERR, s));
	return (print_status(END, s));
}

