/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:17:05 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/06 21:03:39 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		print_status(int status)
{
	if (status < -1 || status > 1)
		return (-1);
	else if (status == ERR)
		write(STDERR, MSG_ERR, ft_strlen(MSG_ERR));
	else if (status == KO)
		write(STDOUT, MSG_KO, ft_strlen(MSG_KO));
	else if (status == OK)
		write(STDOUT, MSG_OK, ft_strlen(MSG_OK));
	return (status);
}
