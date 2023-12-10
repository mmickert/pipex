/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:56:50 by mickert           #+#    #+#             */
/*   Updated: 2023/11/08 15:15:32 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	strlen;
	char			*star;
	size_t			i;

	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup("\0"));
	if (strlen - start < len)
		len = strlen - start;
	star = (char *)ft_calloc((len + 1), sizeof(char));
	if (star == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		star[i] = s[start + i];
		i++;
	}
	star[i] = '\0';
	return (star);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int	strlen;
// 	char			*star;
// 	size_t			i;

// 	strlen = ft_strlen(s);
// 	if (start >= strlen)
// 		return (ft_strdup("\0"));
// 	if (strlen - start < len)
// 		len = strlen - start;
// 	star = (char *)malloc(len + 1);
// 	if (star == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[i] && i < len)
// 	{
// 		star[i] = s[start + i];
// 		i++;
// 	}
// 	star[i] = '\0';
// 	return (star);
// }

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
//     const char *s = "Hello, World!";
//     unsigned int start = 7;
//     size_t len = 5;

//     char *substring = ft_substr(s, start, len);
//     if (substring)
//     {
//         printf("Original String: %s\n", s);
//         printf("Substring: %s\n", substring);

//         free(substring); // Don't forget to free the allocated memory
//     }
//     else
//     {
//         printf("Substring allocation failed.\n");
//     }

//     return 0;
// }

// {
// 	char	*star;
// 	int		strlen;
// 	int		i;
// 	char	*dest;

// 	i = 0;
// 	strlen = ft_strlen(s);
// 	if (strlen > len)
// 		strlen -= len;
// 	while (i > len)
// 		i++;
// 	star = (char *)malloc(strlen);
// 	if (dest == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }