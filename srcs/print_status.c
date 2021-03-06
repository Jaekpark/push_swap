/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:17:05 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/12 23:27:00 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		print_status(int status, t_sort *s)
{
	if (status == ERR)
		write(STDERR, MSG_ERR, ft_strlen(MSG_ERR));
	else if (status == KO)
		write(STDOUT, MSG_KO, ft_strlen(MSG_KO));
	else if (status == OK)
		write(STDOUT, MSG_OK, ft_strlen(MSG_OK));
	else if (status == END)
	{
		if (s != NULL)
			clear_sort(s);
		return (0);
	}
	if (s != NULL)
		clear_sort(s);
	if (status == OK || status == KO)
		return (0);
	return (-1);
}
