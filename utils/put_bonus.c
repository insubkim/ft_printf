/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:09:14 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:43 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	put_precision(char *str, int precision)
{
	int	len;

	if (precision == -1)
		return ;
	len = ft_strlen(str);
	if (precision > len)
	{
		ft_memcpy(str + (precision - len), str, len);
		while (precision > len++)
			*str++ = '0';
	}
}

void	put_width(char *str, int width, char hash, char minus)
{
	int	len;

	if (width == -1)
		return ;
	len = ft_strlen(str);
	if (hash)
		len += 2;
	if (width > len)
	{
		if (minus)
		{
			len = ft_strlen(str);
			if (hash)
				width -= 2;
			while (width > len)
				str[len++] = ' ';
			return ;
		}
		ft_memcpy(str + (width - len), str, len);
		while (width > len++)
			*str++ = ' ';
	}
}

void	put_zero(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			*str = '0';
		str++;
	}
}

void	put_hash(char *str, char minus)
{
	int	len;
	int	i;

	if (minus)
	{
		len = ft_strlen(str);
		ft_memcpy(str + 2, str, len);
		str[0] = '0';
		str[1] = 'x';
		return ;
	}
	i = 0;
	while (str[i] == ' ')
		i++;
	len = ft_strlen(str + i);
	ft_memcpy(str + i + 2, str + i, len);
	str[i] = '0';
	str[i + 1] = 'x';
}
