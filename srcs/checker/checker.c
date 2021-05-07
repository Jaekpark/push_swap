/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:13:15 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/07 21:33:39 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_sort *s;

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
	else if (!(read_buffer()))
}