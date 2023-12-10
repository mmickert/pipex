/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:35:39 by mickert           #+#    #+#             */
/*   Updated: 2023/10/06 16:37:52 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(void)
// {
// 	if (ft_isascii((int) 'e'))
// 		write(1, &"yes", 3);
// 	else
// 		write(1, &"no", 2);
// 	return (0);
// }