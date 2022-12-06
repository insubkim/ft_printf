/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:01 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	is_conv_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || \
			c == 'd' || c == 'i' || c == 'u' || \
			c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	check_format_sequence(const char *format)
{
	format++;
	while (*format && (*format == '#' || *format == '0' || *format == '-' || \
				*format == ' ' || *format == '+'))
		format++;
	while (*format && ft_isdigit(*format))
		format++;
	if (is_conv_specifier(*format))
		return (1);
	if (*format != '.')
		return (0);
	format++;
	while (*format && ft_isdigit(*format))
		format++;
	if (is_conv_specifier(*format))
		return (1);
	return (0);
}
