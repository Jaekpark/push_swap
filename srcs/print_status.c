/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:17:05 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/09 23:15:55 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		print_status(int status, t_sort *s)
{
	if (status < -1 || status > 1)
		return (-1);
	else if (status == ERR)
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
	return (status);
}
