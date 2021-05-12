/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:15:14 by parkjaekw         #+#    #+#             */
/*   Updated: 2021/05/09 20:12:30 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct	s_option
{
	char		specifier;
	int			left_align;
	int			precision;
	int			zero;
	int			width;
	int			sign;
}				t_option;

int				ft_printf(const char *format, ...);
int				check_format(const char *format, va_list ap, t_option *opt);
void			parsing_flag(char c, va_list ap, t_option *opt);
void			parsing_option(char c, va_list ap, t_option *opt);
int				print_format_str(va_list ap, t_option *opt);
void			init_option(t_option *opt);
int				put_char(char c);

int				print_char(t_option *opt, int c);
int				print_str(t_option *opt, char *str);

int				print_num(t_option *opt, int num);
char			*parsing_num(t_option *opt, int num);
int				no_prec_align(t_option *opt, char *str);
int				no_prec_not_align(t_option *opt, char *str);
int				prec_align(t_option *opt, char *str);
int				prec_not_align(t_option *opt, char *str);

int				print_hex(t_option *opt, unsigned int num);
char			*parsing_hex(t_option *opt, unsigned long long num);
int				print_ptr(t_option *opt, unsigned long long num);

#endif
