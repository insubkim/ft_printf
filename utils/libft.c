/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/10/01 08:35:49 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

void	ft_bzero(void *s, int n)
{
	while (n > 0)
	{
		*(char *)s = 0;
		s = s + 1;
		n--;
	}
}

void	*ft_memcpy(void *s1, const void *s2, unsigned int n)
{
	unsigned int	i;

	if (s1 > s2)
	{
		while (n > 0)
		{
			n--;
			((char *)s1)[n] = ((char *)s2)[n];
		}
	}
	else if (s1 < s2)
	{
		i = 0;
		while (i < n)
		{
			((char *)s1)[i] = ((char *)s2)[i];
			i++;
		}
	}
	return (s1);
}
