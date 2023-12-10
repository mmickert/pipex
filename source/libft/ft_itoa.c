/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:35:30 by mickert           #+#    #+#             */
/*   Updated: 2023/10/18 17:48:52 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_length(long nb)
{
	size_t	length;

	length = 1;
	while (nb / 10)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	size_t		i;

	nb = n;
	i = ft_length(n);
	if (n < 0)
	{
		nb *= -1;
		i++;
	}
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	*(str + i) = '\0';
	while (i--)
	{
		*(str + i) = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
