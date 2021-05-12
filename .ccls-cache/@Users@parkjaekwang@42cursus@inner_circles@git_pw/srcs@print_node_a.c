/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:29:27 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/09 22:54:57 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node_a_top(t_node *a, char *inst)
{
	ft_printf(BLUE"| "RESET);
	if ((check_inst_a_top(inst)) == 1)
		print_node_yellow(a);
	else
		print_node_blue(a);
	ft_printf(BLUE" |"RESET);
}

void	print_node_a_bot(t_node *a, char *inst)
{
	ft_printf(BLUE"| "RESET);
	if ((check_inst_a_bot(inst)) == 1)
		print_node_yellow(a);
	else
		print_node_blue(a);
	ft_printf(BLUE" |"RESET);
}

void	print_node_a_mid(t_node *a)
{
	ft_printf(BLUE"| "RESET);
	print_node_blue(a);
	ft_printf(BLUE" |"RESET);
}
