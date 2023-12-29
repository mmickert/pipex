/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:40:48 by mickert           #+#    #+#             */
/*   Updated: 2023/12/29 14:30:04 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fd_open(char *argv, int flag)
{
	int	fd;

	if (flag == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(argv, O_RDONLY, 0777);
	if (fd == -1)
	{
		if (errno == EACCES)
			ft_putstr_fd("zsh: permission denied: ", 2);
		else if (errno == ENOENT)
			ft_putstr_fd("zsh: no such file or directory: ", 2);
		else
			ft_putstr_fd("zsh: error opening the file: ", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd("\n", 2);
		exit (1);
	}
	return (fd);
}

void	free_split(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*command_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(path, X_OK) == 0)
			return (free_split(paths), path);
		i++;
	}
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	free_split(paths);
	exit(127);
}
