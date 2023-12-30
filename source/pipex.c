/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:39:26 by mickert           #+#    #+#             */
/*   Updated: 2023/12/30 12:45:01 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*p_fd[1] = writing & p_f[0] = reading*/
/*pid 0 == child*/
/*0 == wait for all children*/

int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid;
	int		status;

	if (argc < 5 || argc > 5)
	{
		ft_putstr_fd("Usage: <file1> <cmd1> <cmd2> <file2>\n", 2);
		exit(1);
	}
	else if (pipe(p_fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		child_process_1(argv, p_fd, envp);
	status = parent_process(argv, p_fd, envp);
	waitpid(pid, NULL, 0);
	exit (status);
}
// system("leaks pipex");

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*cmd_path;
	int		i;

	i = 0;
	while (argv[i] != '\0' && ((argv[i] >= 9 && argv[i] <= 13)
			|| argv[i] == 32))
		i++;
	if (argv[i] == '\0')
	{
		ft_putstr_fd("zsh: command not found: \n", 2);
		exit(1);
	}
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == 0)
		cmd_path = cmd[0];
	else
		cmd_path = command_path(cmd[0], envp);
	if (execve(cmd_path, cmd, envp) == -1)
	{
		ft_printf("failure execve");
		exit(127);
	}
}

void	child_process_2(char **argv, int *p_fd, char **envp)
{
	int	fd_write;
	int	flag;

	flag = 0;
	fd_write = fd_open(argv[4], flag);
	close(p_fd[1]);
	dup2(fd_write, STDOUT_FILENO);
	close(fd_write);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	execute(argv[3], envp);
	exit(1);
}

int	parent_process(char **argv, int *p_fd, char **envp)
{
	pid_t	pid_2;
	int		status;

	status = 0;
	pid_2 = fork();
	if (pid_2 < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid_2 == 0)
		child_process_2(argv, p_fd, envp);
	else
	{
		close(p_fd[1]);
		waitpid(pid_2, &status, 0);
	}
	return (WEXITSTATUS(status));
}

void	child_process_1(char **argv, int *p_fd, char **envp)
{
	int	fd_in;
	int	flag;

	flag = 1;
	fd_in = fd_open(argv[1], flag);
	close(p_fd[0]);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	execute(argv[2], envp);
	exit(1);
}
