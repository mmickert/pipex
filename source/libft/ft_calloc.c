/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:59:46 by mickert           #+#    #+#             */
/*   Updated: 2023/11/12 11:31:00 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t	totallen;
// 	void	*ptr;

// 	totallen = count * size;
// 	ptr = malloc(totallen);
// 	if (ptr)
// 		ft_memset(ptr, 0, totallen);
// 	return (ptr);
// }
// #include <stdio.h>

// int	main(void)
// {
// 	void *ptr1 = ft_calloc(3, 4);
// 	void *ptr2 = calloc(3, 4);
// 	printf("%p\n", ptr1);
// 	printf("%p", ptr2);
// 	free(ptr1);
// 	free(ptr2);
// 	return 0;
// }