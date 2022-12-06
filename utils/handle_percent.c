/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/01 08:40:48 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_percent_len(int width)
{
	if (width > 1)
		return (width);
	return (1);
}

char	*handle_percent(int width, char zero, char minus)
{
	char	*str;
	int		percent_len;

	percent_len = get_percent_len(width);
	str = (char *)malloc(sizeof(char) * percent_len + 1);
	if (!str)
		return (0);
	ft_bzero(str, percent_len + 1);
	*str = '%';
	put_width(str, width, 0, minus);
	if (zero && minus == 0)
		put_zero(str);
	return (str);
}
