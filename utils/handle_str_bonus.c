/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:36 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	get_str_len(int width, int precision, char *val)
{
	int	len;

	if (!val)
		len = 6;
	else
		len = ft_strlen(val);
	if (len > precision && precision != -1)
		len = precision;
	if (len < width)
		len = width;
	return (len);
}

void	put_null(char *str, int precision)
{
	char	*null;
	int		i;

	null = "(null)";
	if (precision == -1)
		precision = 6;
	i = 0;
	while (precision-- > 0 && i++ < 6)
		*str++ = *null++;
}

void	put_str(char *str, char *val, int precision)
{
	int	len;

	if (!val)
	{
		put_null(str, precision);
		return ;
	}
	len = ft_strlen(val);
	if (len > precision && precision != -1)
		len = precision;
	while (len-- > 0)
		*str++ = *val++;
}

char	*handle_str(char minus, int width, int precision, char *val)
{
	char	*str;
	int		str_len;

	str_len = get_str_len(width, precision, val);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (0);
	ft_bzero(str, str_len + 1);
	put_str(str, val, precision);
	put_width(str, width, 0, minus);
	return (str);
}
