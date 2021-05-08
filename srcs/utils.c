/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:02:29 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/08 18:46:32 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reset_index(t_stack *t)
{
	t_node	*tmp;

	if (!t || !t->top || !t->bot)
		return ;
	tmp = t->bot;
	while (tmp != NULL)
	{
		tmp->idx = -1;
		tmp = tmp->next;
	}
}

int		markup_sorted(t_stack *t)
{
	t_node	*tmp;

	if (ft_lstsize(t) < 1)
		return (-1);
	if (!t->top || !t || !t->bot)
		return (-1);
	tmp = t->top;
	tmp->is_sorted = 1;
	while (tmp->prev != NULL)
	{
		if (tmp->val < tmp->prev->val)
			tmp->prev->is_sorted = 1;
		else if (tmp->val > tmp->prev->val)
		{
			tmp->prev->is_sorted = 0;
			return (-1);
		}
		tmp = tmp->prev;
	}
	if (tmp != t->bot)
		return (-1);
	return (1);
}

int		is_sorted(t_sort *s)
{
	int a_size;
	int b_size;

	if (!s || !s->a || !s->b)
		return (-1);
	a_size = ft_lstsize(s->a);
	b_size = ft_lstsize(s->b);
	if (b_size > 0)
		return (-1);
	else if (a_size == 1 & b_size == 0)
		return (1);
	else if ((markup_sorted(s->a)) > 0)
		return (1);
	return (-1);
}

int		check_num_overflow(char *num)
{
	long long n;

	n = 0;
	if (!num)
		return (-1);
	else if ((ft_strlen(num)) > 11)
		return (-1);
	else if (ft_strlen(num)	== 11 && (num[0] != '-' || num[0] != '+'))
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

void	set_vcflag(t_sort *s)
{
	s->v_flag = 1;
	s->c_flag = 1;
}

int		set_iflag(t_sort *s, char *path)
{
	int		fd;
	char	*tmp;

	fd = 0;
	if (!s || !path || s->i_flag != 0)
		return (-1);
	else if (ft_strlen(path) < 3)
		return (-1);
	else
	{
		tmp = ft_strdup(path + 2);
		if ((fd = open(tmp, O_RDONLY)) < 0)
		{
			free(tmp);
			return (-1);
		}
		s->path = tmp;
		s->i_flag = 1;
		close(fd);
	}
	return (1);
}

int		check_flag(t_sort *s, char **argv)
{
	int i;

	i = 1;
	if (!s || !argv)
		return (-1);
	while (argv[i] != NULL)
	{
		if (s->i_flag == 1 && (ft_strnum(argv[i])) == 1)
			return (-1);
		if ((ft_strnum(argv[i])) == 1)
			return (i);
		else if ((ft_strncmp(argv[i], VFLAG, 3)) == 0)
		{
			if (s->v_flag != 0)
				return (-1);
			s->v_flag = 1;
		}
		else if ((ft_strncmp(argv[i], CFLAG, 3)) == 0)
		{
			if (s->c_flag != 0)
				return (-1);
			s->c_flag = 1;
		}
		else if ((ft_strncmp(argv[i], IFLAG, 2)) == 0)
		{
			if ((set_iflag(s, argv[i])) == -1)
				return (-1);
		}
		else if ((ft_strncmp(argv[i], VCFLAG, 4)) == 0)
		{
			if (s->v_flag != 0 || s->c_flag != 0)
				return (-1);
			set_vcflag(s);
		}
		else if ((ft_strncmp(argv[i], CVFLAG, 4)) == 0)
		{
			if (s->v_flag != 0 || s->c_flag != 0)
				return (-1);
			set_vcflag(s);
		}
		else
			return (i);
		i++;
	}
	return (i);
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

int		is_all_num(char **str)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != NULL)
	{
		if ((ft_strnum(str[i])) == -1)
			return (-1);
		i++;
	}
	return (1);
}
