/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:13:15 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/08 18:49:36 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		is_push_or_swap(char *line)
{
	if (!line)
		return (-1);
	else if ((ft_strncmp(line, "pa", 3)) == 0)
		return (PA);
	else if ((ft_strncmp(line, "pb", 3)) == 0)
		return (PB);
	else if ((ft_strncmp(line, "sa", 3)) == 0)
		return (SA);
	else if ((ft_strncmp(line, "sb", 3)) == 0)
		return (SB);
	else if ((ft_strncmp(line, "ss", 3)) == 0)
		return (SS);
	return (0);
}

int		is_rotate(char *line)
{
	if (!line)
		return (-1);
	else if ((ft_strncmp(line, "ra", 3)) == 0)
		return (RA);
	else if ((ft_strncmp(line, "rb", 3)) == 0)
		return (RB);
	else if ((ft_strncmp(line, "rr", 3)) == 0)
		return (RR);
	else if ((ft_strncmp(line, "rra", 4)) == 0)
		return (RRA);
	else if ((ft_strncmp(line, "rrb", 4)) == 0)
		return (RRB);
	else if ((ft_strncmp(line, "rrr", 4)) == 0)
		return (RRR);
	return (0);
}

int		check_instruction(char *line)
{
	int ret;

	ret = 0;
	if (!line)
		return (-1);
	else if ((ret = is_push_or_swap(line)) > 0)
		return (ret);
	else if ((ret = is_rotate(line)) > 0)
		return (ret);
	return (-1);
}

int		excute_instruction(t_sort *s, int inst)
{
	if (!s || inst < 0)
		return (-1);
	else if (inst == PA)
		pa(s, 1);
	else if (inst == PB)
		pb(s, 1);
	else if (inst == SA)
		sa(s, 1);
	else if (inst == SB)
		sb(s, 1);
	else if (inst == RA)
		ra(s, 1);
	else if (inst == RB)
		rb(s, 1);
	else if (inst == RR)
		rr(s, 1);
	else if (inst == RRA)
		rra(s, 1);
	else if (inst == RRB)
		rrb(s, 1);
	else if (inst == RRR)
		rrr(s, 1);
	return (-1);
}

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
		if (!(inst = check_instruction(line)))
			return (-1);
		else if (!(excute_instruction(s, inst)))
			return (-1);
		if (line != NULL)
			free(line);
	}
	if (line != NULL)
		free(line);
	if ((ret = is_sorted(s)) > 0)
		return (1);
	return (0);
}

void	print_flag(t_sort *s)
{
	printf("|v flag = %d|\n|c flag = %d|\n|i flag = %d|\n", s->v_flag, s->c_flag, s->i_flag);
}

int		main(int argc, char **argv)
{
	t_sort *s;
	int		ret;

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
	else if ((ret = read_buffer(s)) == -1)
		return (print_status(ERR, s));
	return (print_status(ret, s));
}