/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/06 21:09:08 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	get_char_len(int width)
{
	if (width > 1)
		return (width);
	return (1);
}

char	*handle_char(char minus, int width, int val)
{
	char	*str;
	int		char_len;

	char_len = get_char_len(width);
	str = (char *)malloc(sizeof(char) * (char_len + 1));
	if (!str)
		return (0);
	ft_bzero(str, char_len + 1);
	*str = val;
	put_width(str, width, 0, minus);
	return (str);
}
