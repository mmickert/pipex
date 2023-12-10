/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:10:39 by mickert           #+#    #+#             */
/*   Updated: 2023/11/08 15:16:32 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char *str = "aber4567dce";
// 	printf("%d\n", ft_strlen(str));
// 	printf("%lu", strlen(str));
// 	return (0);
// }
