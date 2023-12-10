/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:20:43 by mickert           #+#    #+#             */
/*   Updated: 2023/10/12 17:11:01 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}
// #include <stdio.h>
// int main() 
// {
//     int source[] = {1, 2, 3, 4, 5};
//     int dest[5]; 

//     size_t num_elements = sizeof(source) / sizeof(source[0]);
//     ft_memcpy(dest, source, num_elements * sizeof(int));
//     for (size_t i = 0; i < num_elements; i++) {
//         printf("dest[%zu] = %d\n", i, dest[i]);
//     }
//     return 0;
// }