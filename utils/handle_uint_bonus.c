/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:38 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	get_u_int_len(unsigned int val)
{
	int		len;

	len = 1;
	while (val >= 10)
	{
		len++;
		val = val / 10;
	}
	return (len);
}

int	get_unsigned_len(int width, int precision, unsigned int val)
{
	int	len;

	len = 1;
	while (val >= 10)
	{
		len++;
		val = val / 10;
	}
	if (len < precision)
		len = precision;
	if (len < width)
		len = width;
	return (len);
}

void	put_unsigned(char *str, unsigned int val)
{
	int	len;

	len = get_u_int_len(val);
	while (--len >= 0)
	{
		str[len] = val % 10 + '0';
		val = val / 10;
	}
}

void	put_width_unsigned(char *str, int width, int minus)
{
	int	len;

	if (width == -1)
		return ;
	len = ft_strlen(str);
	if (width > len)
	{
		if (minus)
		{
			len = ft_strlen(str);
			while (width > len)
				str[len++] = ' ';
			return ;
		}
		ft_memcpy(str + (width - len), str, len);
		while (width > len++)
			*str++ = ' ';
	}
}

char	*handle_uint(char *flag, int width, int precision, unsigned int val)
{
	char	*str;
	int		uint_len;

	uint_len = get_unsigned_len(width, precision, val);
	str = (char *)malloc(sizeof(char) * uint_len + 1);
	if (!str)
		return (0);
	ft_bzero(str, uint_len + 1);
	put_unsigned(str, val);
	put_precision(str, precision);
	put_width_unsigned(str, width, flag[2]);
	if (precision == -1 && flag[1] && flag[2] == 0)
		put_zero(str);
	return (str);
}
