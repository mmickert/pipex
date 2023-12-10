/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:39:26 by mickert           #+#    #+#             */
/*   Updated: 2023/12/10 16:08:27 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc < 5 || argc > 5)
	{
		ft_printf("Usage: <file1> <cmd1> <cmd2> <file2>\n");
		exit(1);
	}
	else if (pipe(p_fd) == -1)/*pipe has 2 ends, p_fd[1] = writing && p_fd[0] = reading*/
	{
		perror("Pipe creation failed\n");
		exit(1);
	}
	pid = fork();/*fork returns 1. process ID of the cild in parent 2. 0 == child*/
	if (pid == -1)
	{
		perror("Fork creation failed\n");
		exit(1);
	}
	else if (pid == 0)
		child_process(argv, p_fd, envp);
	waitpid(pid, NULL, 0);
	parent_process(argv, p_fd, envp);
	return (0);
}

/// 
int	execute_parent(char *argv, char **envp, int *p_fd)
{
	char	**cmd;
	char	*cmdpath;
	int		i;
	int		fd;

	i = 0;
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == 0)
		cmdpath = cmd[0];
	else
		cmdpath = cmd_path(cmd[0], envp);
	fd = open(&argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close(p_fd[1]);
	dup2(fd, 1);
	close(fd);
	dup2(p_fd[0], 0);
	close(p_fd[0]);
	execve(cmdpath, cmd, envp);
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	perror("Error in execve");
	exit (1);
}
///

void	parent_process(char **argv, int *p_fd, char **envp)
{
	pid_t	pid_2;
	int		status;

	(void)p_fd;
	status = 0;
	pid_2 = fork();
	if (pid_2 < 0)
	{
		perror("second fork");
		exit(1);
	}
	if (pid_2 == 0)
	{
		if (execute_parent(argv[3], envp, p_fd) == 1)
			perror("Error: executing command\n");
	}
	close(p_fd[1]);
	waitpid(pid_2, &status, 0);
	status = WEXITSTATUS(status);
}

int	execute_child(char *argv, char **envp)
{
	char	**cmd;
	char	*cmdpath;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == 0)
		cmdpath = cmd[0];
	else
		cmdpath = cmd_path(cmd[0], envp);
	execve(cmdpath, cmd, envp);
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	perror("Error in execve");
	exit (1);
}

void	child_process(char **argv, int *p_fd, char **envp)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY, 0777);
	if (fd_in == -1)
	{
		perror("Error: Opening input file\n");
		exit(1);
	}
	close(p_fd[0]);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	dup2(fd_in, STDIN_FILENO);
	close(*p_fd);
	if (execute_child(argv[2], envp) == 1)
		perror("Error: executing command\n");
	exit(1);
}

///////////////

void	free_arrayofstrings(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

char	**get_path(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*cmd_path(char *cmd, char **envp)
{
	char	*temp;
	char	**paths;
	int		i;
	char	*path;

	paths = get_path(envp);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i++], "/");
		temp = ft_strjoin(path, cmd);
		if (access(temp, X_OK) == 0)
		{
			free_arrayofstrings(paths);
			free(path);
			return (temp);
		}
		free(temp);
		free(path);
	}
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	free_arrayofstrings(paths);
	exit(127);
}