/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:43:26 by mickert           #+#    #+#             */
/*   Updated: 2023/11/08 15:17:45 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)ft_calloc((i + 1), sizeof(char));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *src = "abcd";
// 	char *dest;
// 	char *dest2;

// 	dest = ft_strdup(src);
// 	dest2 = strdup(src);
// 	printf("my: %s\n", dest);
// 	printf("real: %s", dest2);
// 	free(dest);
//  free(dest2);
// 	return (0);
// }

// char	*ft_strdup(const char *src)
// {
// 	char	*dest;
// 	int		i;

// 	i = 0;
// 	while (src[i])
// 		i++;
// 	dest = (char *)malloc(i + 1);
// 	if (dest == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (src[i])
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }