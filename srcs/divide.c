/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:05:42 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/02 20:52:11 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_size_and_sort(t_sort *s)
{
	int size;

	if (!s || ft_lstsize(s->a) > 5)
		return (-1);
	size = ft_lstsize(s->a);
	if (size == 2)
		two_sort(s, s->a);
	else if (size == 3)
		three_sort(s, s->a);
	else if (size == 4)
		four_sort(s, s->a);
	else if (size == 5)
		five_sort(s, s->a);
	return (0);
}

int		divide_t(t_sort *s, int size, int cnt)
{
	int p1;
	int p2;
	t_node *max;
	int i;
	
	if (ft_lstsize(s->a) <= 5)
		return (check_size_and_sort(s));
	i = 0;
	max = find_max_idx_addr(s->a);
	p1 = max->idx - (size / 3);
	p2 = max->idx - ((size / 3) * 2);
	if (!s->a || s->a->top == NULL)
		return (-1);
	printf("p1 = %d p2 = %d\n", p1 ,p2);
	while (i <= size)
	{
		if (s->a->top->idx >= p1)
			ra(s, 1);
		else
		{
			pb(s, 1);
			s->b->top->is_sorted = cnt;
			if (ft_lstsize(s->b) >=2 && s->b->top->idx >= p2)
				rb(s, 1);
		}
		i++;
	}
	cnt++;
	divide_t(s, ft_lstsize(s->a), cnt);
	return (1);
}

// int		conquer_t(t_sort *s, t_stack *a, t_stack *b, int size)
// {

// }