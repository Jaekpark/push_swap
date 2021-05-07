/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:43:05 by parkjaekw         #+#    #+#             */
/*   Updated: 2021/02/25 15:26:32 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_format_str(va_list ap, t_option *opt)
{
	int			cnt;

	cnt = 0;
	if (opt->left_align == 1 || opt->precision > -1)
		if (opt->specifier != '%')
			opt->zero = 0;
	if (opt->specifier == 'c')
		cnt += print_char(opt, va_arg(ap, int));
	else if (opt->specifier == 's')
		cnt += print_str(opt, va_arg(ap, char *));
	else if (opt->specifier == 'd' || opt->specifier == 'i')
		cnt += print_num(opt, va_arg(ap, int));
	else if (opt->specifier == 'u')
		cnt += print_num(opt, va_arg(ap, unsigned int));
	else if (opt->specifier == 'x' || opt->specifier == 'X')
		cnt += print_hex(opt, va_arg(ap, unsigned int));
	else if (opt->specifier == 'p')
		cnt += print_ptr(opt, va_arg(ap, unsigned long long));
	else if (opt->specifier == '%')
		cnt += print_char(opt, '%');
	return (cnt);
}

void			parsing_option(char c, va_list ap, t_option *opt)
{
	if (ft_isdigit(c))
	{
		if (opt->precision == -1)
			opt->width = (opt->width * 10) + c - 48;
		else
			opt->precision = (opt->precision * 10) + c - 48;
	}
	else if (c == '*')
	{
		if (opt->precision == -1)
		{
			opt->width = va_arg(ap, int);
			if (opt->width < 0)
			{
				opt->width *= -1;
				opt->left_align = 1;
			}
		}
		else
			opt->precision = va_arg(ap, int);
	}
}

void			parsing_flag(char c, va_list ap, t_option *opt)
{
	if (c == '.')
		opt->precision = 0;
	else if (c == '-')
		opt->left_align = 1;
	else if (c == '0' && opt->width == 0 && opt->precision == -1)
		opt->zero = 1;
	else if (ft_isdigit(c) || c == '*')
		parsing_option(c, ap, opt);
}

int				check_format(const char *format, va_list ap, t_option *opt)
{
	int			i;
	int			cnt;

	cnt = 0;
	i = 0;
	while (*format)
	{
		if (*format != '%')
			cnt += put_char(*(format++));
		else if (*format == '%')
		{
			init_option(opt);
			while (*(++format) && !ft_strchr("csdiupxX%", *format))
				parsing_flag(*format, ap, opt);
			opt->specifier = *(format++);
			cnt += print_format_str(ap, opt);
		}
	}
	return (cnt);
}

int				ft_printf(const char *format, ...)
{
	const char	*format_str;
	t_option	*opt;
	int			cnt;
	va_list		ap;

	cnt = 0;
	if (!(opt = malloc(sizeof(t_option) * 1)))
		return (-1);
	if (!(format_str = ft_strdup(format)))
		return (-1);
	va_start(ap, format);
	cnt = check_format(format_str, ap, opt);
	va_end(ap);
	free(opt);
	free((char *)format_str);
	return (cnt);
}
