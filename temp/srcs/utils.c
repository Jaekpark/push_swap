/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:02:29 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/07 19:58:15 by jaekpark         ###   ########.fr       */
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
			break ;
		}
		tmp = tmp->prev;
	}
	if (tmp != t->bot)
		return (-1);
	return (1);
}

int		check_arg_isnum(char **argv)
{
	int	i;
	int j;
	
	i = 0;
	if (!argv)
		return (-1);
	while (argv[++i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((ft_isnum(argv[i][j]) == -1))
				return (-1);
			j++;
		}
	}
	return (1);
}

int		check_arg_isdup(char **argv)
{
	int i;
	int j;

	i = 0;
	if (!argv)
		return (-1);
	while (argv[++i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strlen(argv[i]) == ft_strlen(argv[j]))
				if (ft_strcmp(argv[i], argv[j]) == 0)
					return (-1);
			j++;
		}
	}
	return (1);
}