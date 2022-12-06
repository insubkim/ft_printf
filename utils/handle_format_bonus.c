/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:14 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*make_str(const char *format, char arg_type, va_list *p_vl)
{
	char	flag[5];
	int		width;
	int		precis;

	get_flag(format, flag);
	width = get_width(format);
	precis = get_precision(format);
	if (arg_type == 'x' )
		return (handle_hex1(flag, width, precis, va_arg(*p_vl, unsigned int)));
	else if (arg_type == 'X')
		return (handle_hex2(flag, width, precis, va_arg(*p_vl, unsigned int)));
	else if (arg_type == 'c')
		return (handle_char(flag[2], width, va_arg(*p_vl, int)));
	else if (arg_type == 'd' || arg_type == 'i')
		return (handle_int(flag, width, precis, va_arg(*p_vl, int)));
	else if (arg_type == 'u')
		return (handle_uint(flag, width, precis, va_arg(*p_vl, unsigned int)));
	else if (arg_type == 'p')
		return (handle_ptr(flag[2], width, va_arg(*p_vl, unsigned long long)));
	else if (arg_type == 's')
		return (handle_str(flag[2], width, precis, va_arg(*p_vl, char *)));
	else if (arg_type == '%')
		return (handle_percent(width, flag[1], flag[2]));
	return (0);
}

int	handle_format(const char **format, int *bytes, va_list *p_vl)
{
	char	*str;
	int		write_bytes;

	if (!check_format_sequence(*format))
		return (0);
	if (check_char_null(*format, p_vl))
		return (handle_char_null(format, bytes));
	if (check_num_precision_zero(*format, p_vl))
		return (handle_num_precision_zero(format, bytes));
	str = make_str(*format, get_arg_type(*format), p_vl);
	if (!str)
		return (0);
	write_bytes = write(1, str, ft_strlen(str));
	*format += 1;
	while (!is_conv_specifier(**format))
		*format += 1;
	*format += 1;
	*bytes += write_bytes;
	free(str);
	return (1);
}
