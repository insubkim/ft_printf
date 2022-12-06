/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 20:11:11 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_hex_len(char hash, int width, int precision, unsigned int val)
{
	int	len;

	len = 1;
	while (val >= 16)
	{
		len++;
		val = val / 16;
	}
	if (len < precision)
		len = precision;
	if (hash)
		len += 2;
	if (len < width)
		len = width;
	return (len);
}

void	put_hex(char *str, unsigned int val)
{
	int				len;
	unsigned int	tmp;

	len = 1;
	tmp = val;
	while (tmp >= 16)
	{
		len++;
		tmp = tmp / 16;
	}
	while (--len >= 0)
	{
		if (val % 16 < 10)
			str[len] = val % 16 + '0';
		else
			str[len] = val % 16 - 10 + 'a';
		val = val / 16;
	}
}

char	*handle_hex1(char *flag, int width, int precision, unsigned int val)
{
	char	*str;
	int		hex_len;

	if (val == 0)
		flag[0] = 0;
	hex_len = get_hex_len(flag[0], width, precision, val);
	str = (char *)malloc(sizeof(char) * hex_len + 1);
	if (!str)
		return (0);
	ft_bzero(str, hex_len + 1);
	put_hex(str, val);
	put_precision(str, precision);
	put_width(str, width, flag[0], flag[2]);
	if (precision == -1 && flag[1] && flag[2] == 0)
		put_zero(str);
	if (flag[0])
		put_hash(str, flag[2]);
	return (str);
}
