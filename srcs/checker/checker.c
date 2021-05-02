/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:13:15 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/02 16:49:44 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_sort(t_sort *s, t_stack *a, t_stack *b)
{
	init_sort(s);
	init_stack(a);
	init_stack(b);
	s->a = a;
	s->b = b;
	s->is_checker = 1;
}
int		check_arg(t_sort *s, int argc, char **argv)
{
	if (ft_)
}

int		main(int argc, char **argv)
{
	t_sort *s;
	t_stack *a;
	t_stack *b;

	if (argc < 2 || !argv)
		return (0);
	if (!(s = malloc(sizeof(t_sort))))
		return (print_status(ERR));
	if ((!(a = malloc(sizeof(t_stack))) || !(b = malloc(sizeof(t_stack)))))
		return (print_status(ERR));
	set_sort(s, a, b);
	if (!(check_arg(s, argc, argv)))
		return (print_status(ERR));
}