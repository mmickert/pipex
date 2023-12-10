/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:02:29 by mickert           #+#    #+#             */
/*   Updated: 2023/11/05 13:28:40 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

void	ft_bzero(void *str, size_t n);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_line(char **new_buffer);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		find_n(char *new_buffer);
int		concat(char **new_buffer, char *buffer);

#endif