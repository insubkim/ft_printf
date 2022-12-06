/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/07 02:48:41 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	vl;
	int		bytes;

	if (!format)
		return (-1);
	va_start(vl, format);
	bytes = 0;
	while (*format)
	{
		if (*format != '%')
			bytes += write(1, format++, 1);
		else
			if (handle_format(&format, &bytes, &vl) == -1)
				return (-1);
	}
	va_end(vl);
	return (bytes);
}
