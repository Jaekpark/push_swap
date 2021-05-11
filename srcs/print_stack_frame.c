/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:27:41 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/09 22:31:17 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_header_color(void)
{
	ft_printf(BLUE"|----------------------------|"RESET);
	ft_printf(MAGENTA" |----------------------------|"RESET"\n");
	ft_printf(BLUE"|"RESET);
	ft_printf(BLUE"          [stack a]         "RESET);
	ft_printf(BLUE"|"RESET MAGENTA" |"RESET);
	ft_printf("          ");
	ft_printf(MAGENTA"[stack b]"RESET);
	ft_printf(MAGENTA"         |\n"RESET);
	ft_printf(BLUE"|----------------------------|"RESET);
	ft_printf(MAGENTA" |----------------------------|"RESET"\n");
	ft_printf(BLUE"| "RESET);
	ft_printf(BLUE"{ data } ( indx ) [ sort ]"RESET);
	ft_printf(BLUE" |"RESET MAGENTA" | "RESET);
	ft_printf(MAGENTA"{ data } ( indx ) [ sort ]"RESET);
	ft_printf(MAGENTA" |"RESET"\n");
	ft_printf(BLUE"|----------------------------|"RESET);
	ft_printf(MAGENTA" |----------------------------|"RESET"\n");
}

int		print_last_color(t_sort *s)
{
	ft_printf(BLUE"|----------------------------|"RESET);
	ft_printf(MAGENTA" |----------------------------|"RESET"\n");
	ft_printf(GREEN"|---------------"RESET);
	ft_printf(GREEN"[   instruction count %6d ]"RESET, s->inst_cnt);
	ft_printf(GREEN"--------------|"RESET"\n");
	usleep(DELAY);
	return (1);
}

void	print_header(void)
{
	ft_printf("|----------------------------|");
	ft_printf(" |----------------------------|\n");
	ft_printf("|");
	ft_printf("          [stack a]         ");
	ft_printf("| |");
	ft_printf("          [stack b]         |\n");
	ft_printf("|----------------------------|");
	ft_printf(" |----------------------------|\n");
	ft_printf("| ");
	ft_printf("{ data } ( indx ) [ sort ]");
	ft_printf(" | | ");
	ft_printf("{ data } ( indx ) [ sort ]");
	ft_printf(" |\n");
	ft_printf("|----------------------------|");
	ft_printf(" |----------------------------|\n");
}

int		print_last(t_sort *s)
{
	ft_printf("|----------------------------|");
	ft_printf(" |----------------------------|\n");
	ft_printf("|---------------");
	ft_printf("[   instruction count %6d ]--------------|\n", s->inst_cnt);
	usleep(DELAY);
	return (1);
}
