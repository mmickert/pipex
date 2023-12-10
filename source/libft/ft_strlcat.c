/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:31:56 by mickert           #+#    #+#             */
/*   Updated: 2023/10/13 16:40:04 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize <= dstlen)
		srclen += dstsize;
	else
		srclen += dstlen;
	while (src[i] && dstlen + 1 < dstsize)
		dst[dstlen++] = src[i++];
	dst[dstlen] = '\0';
	return (srclen);
}

// {
//     size_t  srclen;
//     size_t  dstlen;
//     dstlen = ft_strlen(dst);
//     srclen = ft_strlen(src);
//     if (dstlen > dstsize)
//         dstlen = dstsize;
//     if (dstlen == dstsize || dstsize == 0)
//         return (dstlen + srclen);
//     if (srclen < dstsize - dstlen)
//     {
//         ft_memcpy(dst + dstlen, src, srclen + 1);
//         dst[dstsize - 1] = '\0';
//     }
//     else
//     {
//         ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
//         dst[dstsize - 1] = '\0';
//     }
//     return (dstlen + srclen);
// }

// {
//  size_t dst_len;
// 	size_t src_len;
// 	size_t i;
// 	size_t j;

// 	dst_len = ft_strlen(dst);
// 	src_len = ft_strlen(src);
// 	i = 0;
// 	if (!dst && dstsize == 0)
//         return (src_len);
// 	j = dst_len;
//     if (dst_len < dstsize - 1 && dstsize > 0)
// 	{
// 		while (src[i] && dst_len + i < dstsize - 1) 
//     	{
//      		dst[j] = src[i];
//       		j++;
//       		i++;
//    		}
// 		dst[j] = '\0';
// 	}
//     if (dstsize < dst_len)
//         dst_len = dstsize;
//     return (dst_len + src_len);
// }

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char dest[100];
//     memset(dest, 'r', 15);

//     size_t result = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);

//     printf("%zu\n", result);
//     printf("%s\n", dest);
// 	return (0);
// 	char src[] = "world";
// 	char dest[] = "Hello";
// 	unsigned int nb = 2;
// 	int c = ft_strlcat(dest, src, nb);
// 	printf("New string is: %s\n", dest);
// 	printf("Number of chars: %d\n", c);
// 	printf("real cat: %lu\n", strlcat(dest, src, nb));
// 	return (0);
// }

// {
// 	size_t dst_len;
// 	size_t src_len;
// 	size_t i;
// 	size_t total_len = dst_len + src_len;

// 	dst_len = ft_strlen(dst);
// 	src_len = ft_strlen(src);
// 	i = 0;
// 	if (dstsize <= dst_len)
//         return dstsize + src_len;

//     while (src[i] && dst_len + 1 < dstsize) 
//     {
//         dst[dst_len] = src[i];
//         dst_len++;
//         i++;
//     }

//     if (i < dstsize - dst_len)
//         dst[dst_len] = '\0';
//     else if (dstsize > 0)
//         dst[dstsize - 1] = '\0';

//     return total_len;
// }

// {
// 	size_t c;
// 	size_t d;

// 	if (dstsize <= ft_strlen(dst))
// 		return (dstsize + ft_strlen(src));
// 	c = ft_strlen(dst);
// 	d = 0;
// 	while (src[d] != '\0' && c + 1 < dstsize)
// 	{
// 		dst[c] = src[d];
// 		c++;
// 		d++;
// 	}
// 	dst[c] = '\0';
// 	return (ft_strlen(dst) + ft_strlen(&src[d]));
// }

// {
// 	size_t		result;

// 	result = 0;
// 	while (*dst && result < dstsize)
// 	{
// 		dst++;
// 		result++;
// 	}
// 	if (result >= dstsize)
// 	{
// 		while (*src)
// 		{
// 			src++;
// 			result++;
// 		}
// 		return (result);
// 	}
// 	while (*src)
// 	{
// 		if (result < dstsize - 1)
// 		{
// 			*dst = *src;
// 			dst++;
// 		}
// 		src++;
// 		result++;
// 	}
// 	*dst = '\0';
// 	return (result);
// }

//result soll mir zeigen, wie lang der String sein soll, der created wurde