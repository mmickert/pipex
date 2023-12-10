/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:52:38 by mickert           #+#    #+#             */
/*   Updated: 2023/10/07 13:08:15 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}
// so conditions in return statements are always 0 if untrue, 1 if true.

// int main(void)
// {
// 	if (ft_isalpha((int) 'f')) /* = ft_isalpha('?' -0)*/
// 		write(1, &"yes", 3);
// 	else
// 		write(1, &"no", 2);
// }