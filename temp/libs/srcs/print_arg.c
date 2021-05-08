/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:14:25 by parkjaekw         #+#    #+#             */
/*   Updated: 2021/02/25 15:38:33 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(t_option *opt, int c)
{
	int		cnt;

	cnt = 0;
	if (opt->left_align == 0)
	{
		while ((opt->width)-- - 1 > 0)
		{
			if (opt->specifier == '%' && opt->zero == 1)
				cnt += put_char('0');
			else
				cnt += put_char(' ');
		}
	}
	cnt += put_char(c);
	if (opt->left_align == 1)
		while ((opt->width)-- - 1 > 0)
			cnt += put_char(' ');
	return (cnt);
}

int			print_str(t_option *opt, char *str)
{
	char	*temp;
	int		width;
	int		cnt;
	int		space_cnt;

	if (str == NULL)
		temp = ft_strdup("(null)");
	else
		temp = ft_strdup(str);
	if (opt->precision >= 0 && opt->precision < (int)ft_strlen(temp))
		temp[opt->precision] = '\0';
	cnt = ft_strlen(temp);
	width = opt->width;
	space_cnt = width - cnt;
	if (opt->left_align == 0)
		while (space_cnt-- > 0)
			cnt += put_char(' ');
	ft_putstr_fd(temp, 1);
	if (opt->left_align == 1)
		while (space_cnt-- > 0)
			cnt += put_char(' ');
	free(temp);
	return (cnt);
}

int			print_num(t_option *opt, int num)
{
	int		cnt;
	char	*str;

	cnt = 0;
	if (!(str = parsing_num(opt, num)))
		return (-1);
	if (str[0] == '-')
		opt->sign = 0;
	if (opt->precision <= -1)
	{
		if (opt->left_align == 1)
			cnt += no_prec_align(opt, str);
		else if (opt->left_align == 0)
			cnt += no_prec_not_align(opt, str);
	}
	else if (opt->precision > -1)
	{
		if (opt->left_align == 1)
			cnt += prec_align(opt, str);
		else if (opt->left_align == 0)
			cnt += prec_not_align(opt, str);
	}
	free(str);
	return (cnt);
}

int			print_hex(t_option *opt, unsigned int num)
{
	int		cnt;
	char	*str;

	cnt = 0;
	if (!(str = parsing_hex(opt, (unsigned long long)num)))
		return (-1);
	if (opt->precision <= -1)
	{
		if (opt->left_align == 1)
			cnt += no_prec_align(opt, str);
		else if (opt->left_align == 0)
			cnt += no_prec_not_align(opt, str);
	}
	else if (opt->precision > -1)
	{
		if (opt->left_align == 1)
			cnt += prec_align(opt, str);
		else if (opt->left_align == 0)
			cnt += prec_not_align(opt, str);
	}
	free(str);
	return (cnt);
}

int			print_ptr(t_option *opt, unsigned long long num)
{
	int		cnt;
	char	*temp;
	char	*str;

	cnt = 0;
	if (!(temp = parsing_hex(opt, num)))
		return (-1);
	str = ft_strjoin("0x", temp);
	if (opt->precision <= -1)
	{
		if (opt->left_align == 1)
			cnt += no_prec_align(opt, str);
		else if (opt->left_align == 0)
			cnt += no_prec_not_align(opt, str);
	}
	else if (opt->precision > -1)
	{
		if (opt->left_align == 1)
			cnt += prec_align(opt, str);
		else if (opt->left_align == 0)
			cnt += prec_not_align(opt, str);
	}
	free(temp);
	free(str);
	return (cnt);
}
