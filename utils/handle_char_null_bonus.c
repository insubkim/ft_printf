/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_null_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:11 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	check_char_null(const char *format, va_list *p_vl)
{
	va_list	copy;

	va_copy(copy, *p_vl);
	if (get_arg_type(format) != 'c')
	{
		va_end(copy);
		return (0);
	}
	if ((char)va_arg(copy, int) == 0)
	{
		va_arg(*p_vl, int);
		va_end(copy);
		return (1);
	}
	va_end(copy);
	return (0);
}

void	print_space(int len)
{
	while (len-- > 0)
		write(1, " ", 1);
}

int	handle_char_null(const char **format, int *bytes)
{
	int		char_len;
	char	flag[5];

	char_len = get_char_len(get_width(*format));
	get_flag(*format, flag);
	if (flag[2])
	{
		write(1, "\0", 1);
		if (char_len > 1)
			print_space(char_len - 1);
	}
	else
	{
		if (char_len > 1)
			print_space(char_len - 1);
		write(1, "\0", 1);
	}
	*format += 1;
	while (!is_conv_specifier(**format))
		*format += 1;
	*format += 1;
	*bytes += char_len;
	return (1);
}
