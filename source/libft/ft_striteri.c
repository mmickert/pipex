/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:36:14 by mickert           #+#    #+#             */
/*   Updated: 2023/10/15 11:28:04 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void
// iter(unsigned int i, char * s) {
// 	*s += i;
//     // s[i] = s[i] + i; this one 
//is to use if it is a string, not a single char 
// }

// // i only start at index / unsigned int 
//position and use the function
// #include <stdio.h>
// int main(void)
// {

// 	// {
// 	// 	char s[] = "";
// 	// 	ft_striteri(s, iter);
// 	// 	/* 1 */ check(!strcmp(s, ""));
// 	// }

// 	// {
// 	// 	char s[] = "0";
// 	// 	ft_striteri(s, iter);
// 	// 	/* 2 */ check(!strcmp(s, "0"));
// 	// }

// 	// {
// 		char s[] = "0000000000";
// 		ft_striteri(s, iter);
// 		printf("%s", s);
// 	// }
// 	write(1, "\n", 1);
// 	return (0);
// }