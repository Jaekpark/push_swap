/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:27:44 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/08 18:47:54 by jaekpark         ###   ########.fr       */
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

int		split_argv(t_sort *s)
{
	char **tmp;

	tmp = NULL;
	if (!s || !s->argv)
		return (-1);
	else if (!(tmp = ft_split(s->argv, ' ')))
		return (-1);
	else if (tmp != NULL)
		s->num = tmp;
	return (1);
}

int		read_file(t_sort *s)
{
	char	*line;
	char	*ret;
	int 	fd;
	int		eof;

	eof = 0;
	fd = 0;
	ret = NULL;
	if (!s)
		return (-1);
	else if ((fd = open(s->path, O_RDONLY)) < 0)
		return (-1);
	while ((eof = get_next_line(fd, &line) > 0))
	{
		if (ret == NULL)
			ret = ft_strdup(" ");
		ret = ft_strjoin(ret, line);
		free(line);
	}
	if (line != NULL)
	{
		ret = ft_strjoin(ret, line);
		free(line);
	}
	if (ret != NULL)
		s->argv = ret;
	return (1);
}

int		arr_to_stack(t_sort *s)
{
	int	i;

	if (!s || s->i_flag != 1)
		return (-1);
	else if ((read_file(s)) == -1)
		return (-1);
	else if ((split_argv(s)) == -1)
		return (-1);
	else if (!s->num)
		return (-1);
	i = ft_double_strlen((const char **)s->num);
	if ((is_all_num(s->num)) == -1)
		return (-1);
	while (--i > 0)
		push_arg(ft_atoi(s->num[i]), s->a);
	return (1);
}

int		arg_to_stack(int argc, char **argv, t_sort *s)
{
    int	i;
    int	val;

    i = argc;
    val = 0;
	if (s->i_flag == 1)
		return (-1);
    if (argc < 2 || !argv || !s)
        return (-1);
	while (--i >= 1)
	{
		if (ft_strnum(argv[i]) == 1)
			push_arg(ft_atoi(argv[i]), s->a);
	}
    return (1);
}

int		make_stack(t_sort *s, int argc, char **argv)
{
	int ret;

	ret = 0;
	if (!s || argc < 1 || !argv)
		return (-1);
	else if (s->i_flag == 0)
		ret = arg_to_stack(argc, argv, s);
	else if (s->i_flag == 1)
		ret = arr_to_stack(s);
	return (ret);
}