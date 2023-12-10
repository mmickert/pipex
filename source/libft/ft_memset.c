/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:28:23 by mickert           #+#    #+#             */
/*   Updated: 2023/10/07 12:10:42 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
// #include <stdio.h>

// int main() 
// {
//     char arr[10];
//     ft_memset(arr, 'A', sizeof(arr));
// 	printf("%s\n", arr);
//     return 0;
// }

// size_t			i;
// 	unsigned char	*ptr;

// 	ptr = (unsigned char *)str;
// 	i = 0;
// 	while (i < len)
// 	{
// 		ptr[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return(str);