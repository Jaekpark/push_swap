/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:45:06 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 16:46:18 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*make_new_node(int val)
{
	t_node	*new;

	if (!(new = malloc(sizeof(t_node))))
		return (NULL);
	init_node(new);
	new->val = val;
	return (new);
}

int		check_arg_isdup(char **argv, int idx)
{
	int i;
	int j;

	i = idx;
	if (!argv)
		return (-1);
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_arg_type(t_sort *s, char **argv)
{
	int	i;
	int j;
	int	num_idx;

	if (!argv || ((i = check_flag(s, argv)) == -1))
		return (-1);
	num_idx = i;
	while (argv[i] != NULL)
	{
		if ((check_num_overflow(argv[i])) == -1)
			return (-1);
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (ft_isnum(argv[i][j]) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (num_idx);
}

int		check_num_overflow(char *num)
{
	long long n;

	n = 0;
	if (!num)
		return (-1);
	else if ((ft_numlen(num)) > 11)
		return (-1);
	if (ft_numlen(num) == 11 && (num[0] != '-' && num[0] != '+'))
		return (-1);
	else
	{
		n = ft_atol(num);
		if (n > 2147483647)
			return (-1);
		else if (n < -2147483648)
			return (-1);
	}
	return (1);
}

int		read_file(t_sort *s)
{
	char	*line;
	char	*ret;
	int		fd;
	int		eof;

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
