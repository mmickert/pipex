/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:39:26 by mickert           #+#    #+#             */
/*   Updated: 2023/12/11 17:45:30 by mickert          ###   ########.fr       */
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
	else if (pipe(p_fd) == -1) /*pipe has 2 ends, p_fd[1] = writing && p_f[0] = reading*/
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();/*fork returns 1. process ID of the cild in parent 2. 0 == child*/
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		child_process(argv, p_fd, envp);
	parent_process(argv, p_fd, envp);
	waitpid(pid, NULL, 0); /*3. arg == wait for all children*/
	return (0);
}

void	execute(char *argv, char **envp, int *p_fd)
{
	char	**cmd;
	char	*cmd_path;
	int		i;

	(void)p_fd;
	i = 0;
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == 0)
		cmd_path = cmd[0];
	else
		cmd_path = command_path(cmd[0], envp);
	if (execve(cmd_path, cmd, envp) == -1)
	{
		ft_printf("failure execve");
		exit (1);
	}
	// while (cmd[i])
	// {
	// 	free(cmd[i]);
	// 	i++;
	// }
	// free(cmd);
	// exit(1);
}

void	parent_process(char **argv, int *p_fd, char **envp)
{
	pid_t	pid_2;
	int		status;
	int		fd_write;

	status = 0;
	pid_2 = fork();
	if (pid_2 < 0)
	{
		perror("fork");
		exit(1);
	}
	fd_write = fd_open(argv[4], 0);
	close(p_fd[1]);
	dup2(fd_write, STDOUT_FILENO);
	close(fd_write); 
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	if (pid_2 == 0)
		execute(argv[3], envp, p_fd);
	close(p_fd[1]);
	waitpid(pid_2, 0, 0);
	status = WEXITSTATUS(status);
}

int	fd_open(char *argv, int flag)
{
	int	fd;

	if (flag == 1)
		fd = open(argv, O_RDONLY, 0777);
	else
	{
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	} /*-> make an extra open function with error handling */
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
	}
	return (fd);
}

void	child_process(char **argv, int *p_fd, char **envp)
{
	int	fd_in;
	int	flag;

	flag = 1;
	fd_in = fd_open(argv[1], flag);
	if (fd_in == -1)
		exit (1);
	close(p_fd[0]);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	execute(argv[2], envp, NULL);
	exit(1);
}

//

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
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*command_path(char *cmd, char **envp)
{
	char	*temp;
	char	**paths;
	int		i;
	char	*path;

	printf("hell\n");
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
	printf("hell3\n");
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	free_arrayofstrings(paths);
	exit(127);
}
