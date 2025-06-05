/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:11:33 by marvin            #+#    #+#             */
/*   Updated: 2025/05/29 10:11:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char *files[], char *cmd1[], char *cmd2[], char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
	{
		perror("Error creating pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = execute_child1(fd, cmd1, files[0], envp);
	close(fd[1]);
	pid2 = execute_child2(fd, cmd2, files[1], envp);
	close(fd[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
