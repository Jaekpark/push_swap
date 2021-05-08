/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:50:15 by parkjaekw         #+#    #+#             */
/*   Updated: 2021/02/25 15:01:34 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			no_prec_align(t_option *opt, char *str)
{
	int		cnt;
	int		width;
	int		prec;

	cnt = ft_strlen(str);
	width = opt->width - ft_strlen(str) - opt->sign;
	prec = (opt->precision - cnt) > 0 ? opt->precision - cnt : 0;
	if (opt->sign == 1)
		cnt += put_char('-');
	ft_putstr_fd(str, 1);
	while ((width--) > 0)
		cnt += put_char(' ');
	return (cnt);
}

int			no_prec_not_align(t_option *opt, char *str)
{
	int		cnt;
	int		width;
	int		prec;

	cnt = ft_strlen(str);
	width = opt->width - cnt - opt->sign;
	prec = (opt->precision - cnt) > 0 ? opt->precision - cnt : 0;
	if (opt->zero == 1)
	{
		if (opt->sign == 1)
			cnt += put_char('-');
		while ((width--) > 0)
			cnt += put_char('0');
	}
	else if (opt->zero == 0)
	{
		while ((width--) > 0)
			cnt += put_char(' ');
		if (opt->sign == 1)
			cnt += put_char('-');
	}
	ft_putstr_fd(str, 1);
	return (cnt);
}

int			prec_align(t_option *opt, char *str)
{
	int		cnt;
	int		width;
	int		prec;
	int		blank;

	cnt = ft_strlen(str);
	width = opt->width - cnt - opt->sign;
	prec = (opt->precision - cnt) > 0 ? opt->precision - cnt : 0;
	blank = width - prec;
	if (opt->sign == 1)
		cnt += put_char('-');
	while ((prec--) > 0)
		cnt += put_char('0');
	ft_putstr_fd(str, 1);
	while ((blank--) > 0)
		cnt += put_char(' ');
	return (cnt);
}

int			prec_not_align(t_option *opt, char *str)
{
	int		cnt;
	int		width;
	int		prec;
	int		blank;

	cnt = ft_strlen(str);
	width = opt->width - cnt - opt->sign;
	prec = (opt->precision - cnt) > 0 ? opt->precision - cnt : 0;
	blank = width - prec;
	while ((blank--) > 0)
		cnt += put_char(' ');
	if (opt->sign == 1)
		cnt += put_char('-');
	while ((prec--) > 0)
		cnt += put_char('0');
	ft_putstr_fd(str, 1);
	return (cnt);
}
