/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:53:06 by mickert           #+#    #+#             */
/*   Updated: 2023/11/12 12:20:59 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*new_buffer = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		if (find_n(new_buffer) == 1)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((bytes_read == 0 && (!new_buffer || new_buffer[0] == '\0'))
			|| (bytes_read < 0))
		{
			free(new_buffer);
			return (new_buffer = NULL, NULL);
		}
		if (concat(&new_buffer, buffer) == 0)
			return (NULL);
	}
	return (line = ft_line(&new_buffer), line);
}

char	*ft_line(char **new_buffer)
{
	int		i;
	char	*line;
	char	*temp;
	int		new_buffer_len;

	i = 0;
	new_buffer_len = 0;
	while ((*new_buffer)[i])
	{
		if ((*new_buffer)[i] == '\n')
			break ;
		i++;
	}
	line = ft_substr(*new_buffer, 0, i + 1);
	new_buffer_len = ft_strlen(*new_buffer) - i;
	temp = ft_substr(*new_buffer, i + 1, new_buffer_len);
	if (!line || !temp)
		return (free(line), free(temp), NULL);
	free(*new_buffer);
	(*new_buffer) = NULL;
	(*new_buffer) = ft_strdup(temp);
	free(temp);
	if (!(*new_buffer))
		return (free(line), NULL);
	return (line);
}

int	concat(char **new_buffer, char *buffer)
{
	char	*temp;

	if (*new_buffer)
	{
		temp = ft_strjoin(*new_buffer, buffer);
		if (!temp)
			return (0);
		free(*new_buffer);
		*new_buffer = NULL;
		*new_buffer = ft_strdup(temp);
		free(temp);
	}
	else
		*new_buffer = ft_strdup(buffer);
	return (1);
}

int	find_n(char *new_buffer)
{
	int		i;

	i = 0;
	if (!new_buffer)
		return (0);
	while (new_buffer[i])
	{
		if (new_buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// void	ft_bzero(void *str, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		((unsigned char *)str)[i] = 0x00;
// 		i++;
// 	}
// }

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*r;
// 	int		fd;

// 	r = NULL;
// 	fd = open("test.txt", O_RDONLY);
// 	r = get_next_line(fd);
// 	char *t = get_next_line(fd);
// 	char *y = get_next_line(fd);
// 	if (r)
// 	{
// 		printf("main: %s\n", r);
// 		printf("2. %s\n", t);
// 		printf("3. %s", y);
// 		free(r);
// 	}
// 	close(fd);
// 	return (0);
// }
