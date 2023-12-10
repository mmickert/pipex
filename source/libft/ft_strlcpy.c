/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:14:33 by mickert           #+#    #+#             */
/*   Updated: 2023/12/03 18:20:47 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	copied;

	copied = 0;
	if (dstsize > 0)
	{
		while (*src && dstsize > 1)
		{
			*dst++ = *src++;
			dstsize--;
			copied++;
		}
		if (dstsize > 0)
		{
			*dst = '\0';
			dstsize--;
		}
	}
	while (*src)
	{
		src++;
		copied++;
	}
	return (copied);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char src[] = "It's my birthday soon!";
// 	char dst[23];
// 	size_t len = 20;

// 	printf("%zu\n", ft_strlcpy(dst, src, len));
// 	printf("source: %s\n", src);
// 	printf("dest: %s\n", dst);
// 	return (0);
// }