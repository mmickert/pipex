/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:45:39 by mickert           #+#    #+#             */
/*   Updated: 2023/10/21 17:28:59 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*st1;
	const unsigned char	*st2;

	st1 = (const unsigned char *) s1;
	st2 = (const unsigned char *) s2;
	while (n > 0)
	{
		if (*st1 < *st2)
			return (*st1 - *st2);
		else if (*st1 > *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
		n--;
	}
	return (0);
}

	// if (n == 0)
	// 	return (0);
	// else if (*st1 == '\0' && *st2 == '\0')
	// 	return (0);
	// else if (*st1 == '\0')
	// 	return (st1 - st2);
	// else
	// 	return (st2 - st1);

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char *str = "abcd";
// 	char *str2 = "yh";
// 	size_t n = 2;

// 	printf("%d\n", memcmp(str, str2, n));
// 	printf("%d", ft_memcmp(str, str2, n));
// }