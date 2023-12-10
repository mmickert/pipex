/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:27:15 by mickert           #+#    #+#             */
/*   Updated: 2023/10/15 11:33:04 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	newc;

	i = ft_strlen(str);
	newc = c;
	while (i >= 0)
	{
		if (str[i] == newc)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%s", ft_strrchr("ab", 'c'));
// 	return (0);
// }