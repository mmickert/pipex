/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:11:33 by mickert           #+#    #+#             */
/*   Updated: 2023/10/07 12:19:35 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = 0x00;
		i++;
	}
}
// #include <stdio.h>
// # include <string.h>
// int main()
// {
//     char buffer[10]; 
//     size_t buffer_size = sizeof(buffer);

//     strcpy(buffer, "Hello, C!");
//     printf("Initial buffer content: %s\n", buffer);
//     ft_bzero(buffer, buffer_size);
//     printf("Buffer after ft_bzero: %s\n", buffer);
//     return 0;
// }