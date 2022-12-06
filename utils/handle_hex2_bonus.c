/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:20 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	put_hex2(char *str, unsigned int val)
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
			str[len] = val % 16 - 10 + 'A';
		val = val / 16;
	}
}

void	put_hash2(char *str, char minus)
{
	int	len;
	int	i;

	if (minus)
	{
		len = ft_strlen(str);
		ft_memcpy(str + 2, str, len);
		str[0] = '0';
		str[1] = 'X';
		return ;
	}
	i = 0;
	while (str[i] == ' ')
		i++;
	len = ft_strlen(str + i);
	ft_memcpy(str + i + 2, str + i, len);
	str[i] = '0';
	str[i + 1] = 'X';
}

char	*handle_hex2(char *flag, int width, int precision, unsigned int val)
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
	put_hex2(str, val);
	put_precision(str, precision);
	put_width(str, width, flag[0], flag[2]);
	if (precision == -1 && flag[1] && flag[2] == 0)
		put_zero(str);
	if (flag[0])
		put_hash2(str, flag[2]);
	return (str);
}
