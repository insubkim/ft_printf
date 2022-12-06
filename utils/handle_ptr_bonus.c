/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:32 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	get_ptr_len(char hash, int width, int precision, unsigned long long val)
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

void	put_ptr(char *str, unsigned long long val)
{
	int						len;
	unsigned long long		tmp;

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

char	*handle_ptr(char minus, int width, unsigned long long val)
{
	char	*str;
	int		ptr_len;

	ptr_len = get_ptr_len(1, width, -1, val);
	str = (char *)malloc(sizeof(char) * ptr_len + 1);
	if (!str)
		return (0);
	ft_bzero(str, ptr_len + 1);
	put_ptr(str, val);
	put_width(str, width, 1, minus);
	put_hash(str, minus);
	return (str);
}
