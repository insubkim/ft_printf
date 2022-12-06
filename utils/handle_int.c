/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 20:13:18 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_int_len(char *flag, int width, int precision, int val)
{
	int				len;
	unsigned int	u_val;

	u_val = val;
	if (val < 0)
		u_val = -val;
	len = get_u_int_len(u_val);
	if (len < precision)
		len = precision;
	if (flag[3] || flag[4] || val < 0)
		len++;
	if (len < width)
		len = width;
	return (len);
}

void	put_int(char *str, int val)
{
	int				len;
	unsigned int	u_val;

	u_val = val;
	if (val < 0)
		u_val = -val;
	len = get_u_int_len(u_val);
	while (--len >= 0)
	{
		str[len] = u_val % 10 + '0';
		u_val = u_val / 10;
	}
}

void	put_width_int(char *str, int width, char *flag, int val)
{
	int	len;

	if (width == -1)
		return ;
	len = ft_strlen(str);
	if (flag[3] || flag[4] || val < 0)
		len += 1;
	if (width > len)
	{
		if (flag[2])
		{
			len = ft_strlen(str);
			if (flag[3] || flag[4] || val < 0)
				width -= 1;
			while (width > len)
				str[len++] = ' ';
			return ;
		}
		ft_memcpy(str + (width - len), str, len);
		while (width > len++)
			*str++ = ' ';
	}
}

void	put_sign(char *str, char *flag, int val)
{
	int	len;
	int	i;

	i = 0;
	if (flag[2])
	{
		len = ft_strlen(str);
		ft_memcpy(str + 1, str, len);
	}
	else
	{
		while (str[i] == ' ')
			i++;
		len = ft_strlen(str + i);
		ft_memcpy(str + i + 1, str + i, len);
	}
	if (val < 0)
		str[i] = '-';
	else if (flag[3])
		str[i] = ' ';
	else if (flag[4])
		str[i] = '+';
}

char	*handle_int(char *flag, int width, int precision, int val)
{
	char	*str;
	int		int_len;

	int_len = get_int_len(flag, width, precision, val);
	str = (char *)malloc(sizeof(char) * int_len + 1);
	if (!str)
		return (0);
	ft_bzero(str, int_len + 1);
	put_int(str, val);
	put_precision(str, precision);
	put_width_int(str, width, flag, val);
	if (precision == -1 && flag[1] && flag[2] == 0)
		put_zero(str);
	if (flag[3] || flag[4] || val < 0)
		put_sign(str, flag, val);
	return (str);
}
