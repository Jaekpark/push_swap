/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:13:15 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 18:36:20 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		read_buffer(t_sort *s)
{
	char	*line;
	int		eof;
	int		inst;
	int		ret;

	if (!s || ft_lstsize(s->b) != 0 || ft_lstsize(s->a) == 0)
		return (-1);
	while ((eof = get_next_line(0, &line)) > 0)
	{
		if ((inst = check_instruction(line)) == -1)
			return (instruction_error(line));
		else if ((excute_instruction(s, inst)) == -1)
			return (instruction_error(line));
		if (line != NULL)
			free(line);
	}
	if (line != NULL)
		free(line);
	if ((ret = is_sorted(s)) > 0)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_sort	*s;
	int		ret;

	s = NULL;
	if (argc <= 1 || !argv)
		return (print_status(END, s));
	else if (argc > 10000)
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
	else if ((ret = read_buffer(s)) == -1)
		return (print_status(ERR, s));
	return (print_status(ret, s));
}
