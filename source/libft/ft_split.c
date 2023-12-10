/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:35:17 by mickert           #+#    #+#             */
/*   Updated: 2023/10/20 13:20:53 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen_split(const char *s, const char c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != c && s[i] != '\0')
	{
		++i;
	}
	return (i);
}

static size_t	countwords(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else if (*s != c)
		{
			count++;
			s += strlen_split(s, c);
		}
	}
	return (count);
}

static int	fill_split(char *s, char c, size_t i, char **strsplit)
{
	size_t	len;

	if (strsplit == NULL)
		return (0);
	if (ft_strchr(s, c) == NULL)
		len = ft_strlen(s);
	else
		len = strlen_split(s, c);
	strsplit[i] = ft_substr(s, 0, len);
	if (strsplit[i] == NULL)
	{
		while (i > 0)
		{
			free(strsplit[i - 1]);
			i--;
		}
		free(strsplit);
		return (0);
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	char	**strsplit;
	int		filled;

	i = 0;
	strsplit = (char **)ft_calloc((countwords(s, c) + 1), sizeof(char *));
	if (s == NULL || strsplit == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s)
		{
			filled = fill_split((char *)s, c, i, strsplit);
			if (filled == FALSE)
				return (NULL);
			i++;
			s += strlen_split(s, c);
		}
	}
	return (strsplit);
}

// #include <stdio.h>
// #include <stdlib.h>

// size_t	countwords(char const *s, char c);

// char	**ft_split(const char *s, char c);

// int main(void) {
//     char input[] = "lorem ipsum dolor ";
//     char separator = ' ';

//     printf("Input string: %s\n", input);
//     printf("Separator: '%c'\n", separator);

//     char **result = ft_split(input, separator);
//     if (result == NULL) {
//         printf("Split failed or returned NULL\n");
//     } else {
//         int i = 0;
//         while (result[i] != NULL) {
//             printf("%s\n", result[i]);
//             i++;
//         }
//     }

//     // Free the memory allocated for the result
//     for (int i = 0; result[i] != NULL; i++) {
//         free(result[i]);
//     }
//     free(result);

//     return 0;
// }

// char	**ft_malloc(const char *s, char c)
// {
// 	char	**strlsplit;

// 	strlsplit = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
// 	if (!s || !strlsplit)
// 		return (NULL);
// 	return (strlsplit);
// }

// int	ft_free_malloc(char **s, size_t i)
// {
// 	while (i > 0)
// 	{
// 		free(s[i - 1]);
// 		i--;
// 	}
// 	free(s);
// 	return (1);
// }

// char	**ft_split_string(char **strsplit, const char *s,
// 		unsigned int start, size_t len)
// {
// 	char *result = (char *)malloc(len + 1);
// 	if (!result)
// 		return NULL;
// 	size_t i = 0;
// 	while (s[i] && i < len)
// 	{
// 		result[i] = s[start + i];
// 		i++;
// 	}
// 	result[i] = '\0';

// 	size_t j = 0;
// 	while (strsplit[j])
// 		j++;
// 	strsplit[j] = result;
// 	return strsplit;
// }

// char **ft_split(const char *s, char c)
// {
//     size_t i;
//     char **strsplit;
// 	strsplit = ft_malloc(s, c);
// 	i = 0;
//     if (!s || !strsplit)
//         return (NULL);
//     while (*s)
//     {
//         while (*s == c && *s)
//             s++;
//         if (*s)
//         {
//             size_t len;
//             if (!ft_strchr(s, c))
//                 len = ft_strlen(s);
//             else
//                 len = (size_t)(ft_strchr(s, c) - s);
//             strsplit[i] = ft_substr(s, 0, len);
//             strsplit = ft_split_string(strsplit, s, 0, len);
//             if (!strsplit[i] && ft_free_malloc(strsplit, i))
//                 return (NULL);
//             s += len;
//             i++;
//         }
//     }
//     return (strsplit[i] = NULL, strsplit);
// }

// static void	free_arr(char **arr)
// {
// 	if (arr == NULL)
// 		return ;
// 	while (*arr != NULL)
// 	{
// 		free(*arr);
// 		++arr;
// 	}
// 	free(arr);
// }

// char	**ft_split(const char *s, char c)
// {
// 	size_t	len;
// 	size_t	i;
// 	char	**strsplit;

// 	i = 0;
// 	strsplit = (char **)ft_calloc(countwords(s, c) + 1, sizeof(char *));
// 	if (!s || !strsplit)
// 		return (NULL);
// 	while (*s)
// 	{
// 		while (*s == c && *s)
// 			s++;
// 		if (*s)
// 		{
// 			if (!ft_strchr(s, c))
// 				len = ft_strlen(s);
// 			else
// 				len = ft_strchr(s, c) - s;
// 			strsplit[i] = ft_substr(s, 0, len);
// 			if (!strsplit[i])
// 				free_arr(strsplit);
// 			s += len;
// 			i++;
// 		}
// 	}
// 	strsplit[i] = NULL;
// 	return (strsplit);
// }
