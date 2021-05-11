/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 02:12:42 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 14:03:27 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_path(char *path)
{
	int i;

	i = ft_strlen(path);
	if (!path || i < 3)
		return (-1);
	else if (i == 3)
	{
		if ((ft_isalnum(path[2])) == 0)
			return (-1);
	}
	else if ((ft_isalnum(path[i - 1])) == 0)
		return (-1);
	return (1);
}

int		check_iflag(t_sort *s, char *path)
{
	int		fd;
	char	*tmp;

	fd = 0;
	if (!s || !path || s->i_flag != 0)
		return (-1);
	else if ((check_path(path)) == -1)
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

int		check_vcflag(t_sort *s, int index)
{
	if (!s)
		return (-1);
	if (index == 0)
	{
		if (s->is_checker == 0 || s->v_flag != 0)
			return (-1);
		s->v_flag = 1;
	}
	else if (index == 1)
	{
		if (s->is_checker == 0 || s->c_flag != 0)
			return (-1);
		s->c_flag = 1;
	}
	else if (index == 2)
	{
		if ((s->v_flag != 0 || s->c_flag != 0) || s->is_checker == 0)
			return (-1);
		s->c_flag = 1;
		s->v_flag = 1;
	}
	return (1);
}

int		check_all_flag(t_sort *s, char *argv)
{
	if ((ft_strncmp(argv, VFLAG, 3)) == 0)
		return (check_vcflag(s, 0));
	else if ((ft_strncmp(argv, CFLAG, 3)) == 0)
		return (check_vcflag(s, 1));
	else if ((ft_strncmp(argv, IFLAG, 2)) == 0)
		return (check_iflag(s, argv));
	else if ((ft_strncmp(argv, CVFLAG, 4)) == 0)
		return (check_vcflag(s, 2));
	else if ((ft_strncmp(argv, VCFLAG, 4)) == 0)
		return (check_vcflag(s, 2));
	return (-1);
}

int		check_flag(t_sort *s, char **argv)
{
	int i;

	i = 0;
	while (argv[++i] != NULL)
	{
		if ((s->i_flag == 1 && ((ft_strnum(argv[i])) == 1)))
			return (-1);
		else if (s->is_checker == 0 && (s->v_flag == 1 || s->c_flag == 1))
			return (-1);
		else if (ft_strnum(argv[i]) == 1)
			break ;
		else if (check_all_flag(s, argv[i]) == -1)
			return (-1);
	}
	return (i);
}
