/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:32 by mickert           #+#    #+#             */
/*   Updated: 2023/10/13 13:14:53 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	newc;

	i = 0;
	newc = c;
	while (str[i] && newc != str[i])
		i++;
	if (str[i] == newc)
		return ((char *)&str[i]);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *result = ft_strchr("abcd", 'd');
// 	printf("%s", result);
// 	return (0);
// }
