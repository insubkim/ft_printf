/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num_precision_zero.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/01 08:33:41 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_num_type(char type)
{
	if (type == 'i' || type == 'd' || type == 'u' || type == 'x' || type == 'X')
		return (1);
	return (0);
}

int	check_num_precision_zero(const char *format, va_list *p_vl)
{
	va_list	copy;
	char	type;

	va_copy(copy, *p_vl);
	type = get_arg_type(format);
	if (!is_num_type(type))
	{
		va_end(copy);
		return (0);
	}
	if (va_arg(copy, int) == 0 && get_precision(format) == 0)
	{
		va_end(copy);
		va_arg(*p_vl, int);
		return (1);
	}
	va_end(copy);
	return (0);
}

void	print_sign(char *flag)
{
	if (flag[4])
		write(1, "+", 1);
	else if (flag[3])
		write(1, " ", 1);
}

int	get_num_precision_zero_len(const char *format, char type, char *flag)
{
	int	width;

	width = get_width(format);
	if (width == -1 && (flag[3] || flag[4]) && (type == 'i' || type == 'd'))
		return (1);
	else if (width > 1 && (flag[3] || flag[4]) && (type == 'i' || type == 'd'))
		return (width);
	else if (width > 0)
		return (width);
	return (0);
}

int	handle_num_precision_zero(const char **format, int *bytes)
{
	int		len;
	char	type;
	char	flag[5];

	type = get_arg_type(*format);
	get_flag(*format, flag);
	len = get_num_precision_zero_len(*format, type, flag);
	if (flag[2] && (flag[3] || flag[4]) && (type == 'i' || type == 'd'))
	{
		print_sign(flag);
		print_space(len - 1);
	}
	else if (flag[4] && (flag[3] || flag[4]) && (type == 'i' || type == 'd'))
	{
		print_space(len - 1);
		print_sign(flag);
	}
	else
		print_space(len);
	*format += 1;
	while (!is_conv_specifier(**format))
		*format += 1;
	*format += 1;
	*bytes += len;
	return (1);
}
