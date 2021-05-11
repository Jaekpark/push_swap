/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:29:52 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/09 21:30:04 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node_b_top(t_node *b, char *inst)
{
	ft_printf(MAGENTA" | "RESET);
	if ((check_inst_b_top(inst)) == 1)
		print_node_yellow(b);
	else
		print_node_magenta(b);
	ft_printf(MAGENTA" |"RESET"\n");
}

void	print_node_b_bot(t_node *b, char *inst)
{
	ft_printf(MAGENTA" | "RESET);
	if ((check_inst_b_bot(inst)) == 1)
		print_node_yellow(b);
	else
		print_node_magenta(b);
	ft_printf(MAGENTA" |"RESET"\n");
}

void	print_node_b_mid(t_node *b)
{
	ft_printf(MAGENTA" | "RESET);
	print_node_magenta(b);
	ft_printf(MAGENTA" |"RESET"\n");
}
