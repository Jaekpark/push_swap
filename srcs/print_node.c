/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:31:27 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 04:12:13 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *t)
{
	ft_printf("{%6d}", t->val);
	ft_printf(" (%6d)", t->idx);
	ft_printf(" [%6d]", t->is_sorted);
}

void	print_node_yellow(t_node *t)
{
	ft_printf(YELLOW"{%6d}"RESET, t->val);
	ft_printf(YELLOW" (%6d)"RESET, t->idx);
	ft_printf(YELLOW" [%6d]"RESET, t->is_sorted);
}

void	print_node_magenta(t_node *t)
{
	ft_printf(MAGENTA"{%6d}"RESET, t->val);
	ft_printf(MAGENTA" (%6d)"RESET, t->idx);
	ft_printf(MAGENTA" [%6d]"RESET, t->is_sorted);
}

void	print_node_blue(t_node *t)
{
	ft_printf(BLUE"{%6d}"RESET, t->val);
	ft_printf(BLUE" (%6d)"RESET, t->idx);
	ft_printf(BLUE" [%6d]"RESET, t->is_sorted);
}
