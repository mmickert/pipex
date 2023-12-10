/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:39:26 by mickert           #+#    #+#             */
/*   Updated: 2023/12/10 13:41:45 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	(void)argv;
	if (argc < 5 || argc > 5)
	{
		ft_printf("Usage: <file1> <cmd1> <cmd2> <file2>\n");
		exit(1);
	}
	if (pipe(p_fd) == -1)/*pipe has 2 ends, p_fd[1] = writing && p_fd[0] = reading*/
	{
		perror("Pipe creation failed\n");
		exit(1);
	}
	pid = fork();/*fork returns 1. process ID of the cild in parent 2. 0 in child*/
	if (pid < 0)
	{
		perror("Fork creation failed\n");
		exit(1);
	}
	else if (pid == 0)
		printf("Child process (PID: %d)\n", getpid());
	else
		printf("Parent process (PID: %d)\n", getpid());
	parent_process(argv, p_fd, envp);
	return (0);
}

void	parent_process(char **argv, int p_fd, char **envp)
{
	int	fd;
	close(p_fd[0]);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Opening input file\n");
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	if (execute(argv[2], envp) == 1)
		perror("Error: executing command\n");
	exit(1);
}

int	execute(char **argv, char **envp)
{
	char	**cmd;
	char	*cmdpath;

	cmd = ft_split(argv[2], ' ');
	if (access(cmd[0], X_OK) == 0)
		cmdpath = cmd[0];
	else
		cmdpath = cmd_path(cmd[0], envp);
	execve(cmdpath, cmd, envp);
	free_split_strings(cmd);
}
