/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:04 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	get_arg_type(const char *format)
{
	while (*format)
		if (is_conv_specifier(*++format))
			return (*format);
	return (0);
}

int	is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

void	get_flag(const char *format, char *flag)
{
	int	i;

	format++;
	i = 0;
	while (i < 5)
		flag[i++] = 0;
	while (is_flag(*format))
	{
		if (*format == '#')
			flag[0] = 1;
		else if (*format == '0')
			flag[1] = 1;
		else if (*format == '-')
			flag[2] = 1;
		else if (*format == ' ')
			flag[3] = 1;
		else if (*format == '+')
			flag[4] = 1;
		format++;
	}
}

int	get_width(const char *format)
{
	int	width;

	format++;
	while (is_flag(*format))
		format++;
	width = -1;
	if ('1' <= *format && *format <= '9')
	{
		width = 0;
		while (ft_isdigit(*format))
			width = width * 10 + *format++ - '0';
	}
	return (width);
}

int	get_precision(const char *format)
{
	int	precision;

	format++;
	while (is_flag(*format))
		format++;
	while (ft_isdigit(*format))
		format++;
	precision = -1;
	if (*format++ == '.')
	{
		precision = 0;
		while (ft_isdigit(*format))
			precision = precision * 10 + *format++ - '0';
	}
	return (precision);
}
