/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:40:22 by mickert           #+#    #+#             */
/*   Updated: 2023/12/10 13:21:21 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include "../source/libft/libft.h"

int		main(int argc, char **argv, char **envp);
void	parent_process(char **argv, int p_fd, char **envp);
int		execute(char **argv, char **envp);

#endif