/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:45:54 by mickert           #+#    #+#             */
/*   Updated: 2023/10/09 16:07:20 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *) s1;
	st2 = (unsigned char *) s2;
	while (*st1 && *st2 && n > 0)
	{
		if (*st1 < *st2)
			return (-1);
		else if (*st1 > *st2)
			return (1);
		st1++;
		st2++;
		n--;
	}
	if (n == 0)
		return (0);
	else if (*st1 == '\0' && *st2 == '\0')
		return (0);
	else if (*st1 == '\0')
		return (-1);
	else
		return (1);
}
