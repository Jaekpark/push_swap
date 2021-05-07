/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:46:29 by parkjaekw         #+#    #+#             */
/*   Updated: 2021/02/25 15:18:13 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_char(char c)
{
	return (write(1, &c, 1));
}

void		init_option(t_option *opt)
{
	opt->left_align = 0;
	opt->precision = -1;
	opt->sign = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->specifier = 0;
}

char		*parsing_num(t_option *opt, int num)
{
	char	*str;

	str = NULL;
	if (num == 0 && opt->precision == 0)
		str = ft_strdup("");
	else if (opt->specifier == 'u')
		str = ft_uitoa((unsigned int)num);
	else if (num >= 0)
		str = ft_itoa(num);
	else if (num < 0)
	{
		opt->sign = 1;
		str = ft_itoa(-num);
	}
	return (str);
}

char		*parsing_hex(t_option *opt, unsigned long long num)
{
	char	*str;

	str = NULL;
	if (num == 0 && opt->precision == 0)
		str = ft_strdup("");
	else if (opt->specifier == 'x' || opt->specifier == 'p')
		str = ft_utoa(num, "0123456789abcdef");
	else if (opt->specifier == 'X')
		str = ft_utoa(num, "0123456789ABCDEF");
	else
		return (NULL);
	return (str);
}
