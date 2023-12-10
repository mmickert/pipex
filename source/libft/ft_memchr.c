/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:58:47 by mickert           #+#    #+#             */
/*   Updated: 2023/10/13 14:45:02 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		newc;
	const unsigned char	*s;

	i = 0;
	newc = c;
	s = (unsigned char *)str;
	while (i < n)
	{
		if (*s == newc)
			return ((void *)s);
		i++;
		s++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("%p\n", ft_memchr("abcv", 'v', 4));	
// 	printf("%p", memchr("abcv", 'v', 4));
// 	return (0);
// }