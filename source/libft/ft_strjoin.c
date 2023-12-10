/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:01:51 by mickert           #+#    #+#             */
/*   Updated: 2023/12/02 14:45:24 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*joinedstr;
	int		i;
	int		j;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joinedstr = (char *)ft_calloc((s1len + s2len + 1), sizeof(char));
	if (joinedstr == NULL)
		return (free(joinedstr), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		joinedstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		joinedstr[i++] = s2[j++];
	return (joinedstr[i] = 0, joinedstr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1 = "abc";
// 	char	*s2 = "def";
// 	char	*ptr = ft_strjoin(s1, s2);
//	printf("%s", ptr);
//	free(ptr);
// 	return 0;
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	s1len;
// 	size_t	s2len;
// 	char	*joinedstr;
// 	int		i;
// 	int		j;

// 	s1len = ft_strlen(s1);
// 	s2len = ft_strlen(s2);
// 	joinedstr = (char *)malloc(s1len + s2len + 1);
// 	if (joinedstr == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 	{
// 		joinedstr[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		joinedstr[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	return (joinedstr[i] = 0, joinedstr);
// }