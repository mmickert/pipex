/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:34:41 by mickert           #+#    #+#             */
/*   Updated: 2023/10/15 11:17:32 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (i <= j && ft_strchr(set, s1[i]))
		i++;
	if (i > j)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	while (j >= i && ft_strchr(set, s1[j -1]))
		j--;
	str = malloc(j - i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[i], j - i + 1);
	return (str);
}

// j - 1 weil array bei 0 beginnt

// #include <stdio.h>

// int main() 
// {
//     const char *input = " a a Hello, World!  a a";
//     const char *set = " a";

//     char *trimmed = ft_strtrim(input, set);

//     if (trimmed) {
//         printf("Original: \"%s\"\n", input);
//         printf("Trimmed:  \"%s\"\n", trimmed);

//         free(trimmed); // Don't forget to free the allocated memory when done
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }