/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:33:03 by mickert           #+#    #+#             */
/*   Updated: 2023/10/13 15:59:13 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	minus;

	nbr = 0;
	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * minus);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	char *str = "\010 7";
// 	int i;
// 	int z;
// 	i = ft_atoi(str);
// 	printf("my result is %d\n", i);
// 	z = atoi(str);
// 	printf("real result %d\n", z);
// 	return (0);
// }
