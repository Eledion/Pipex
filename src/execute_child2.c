/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executechild2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:59:51 by marvin            #+#    #+#             */
/*   Updated: 2025/05/29 10:59:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	setup_child2(int fd[], char *outfile)
{
	int	fd_out;

	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Error duplicating fd[0] to STDIN");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	fd_out = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		perror("Error duplicating fd_out to STDOUT");
		exit(EXIT_FAILURE);
	}
	close(fd_out);
}

pid_t	execute_child2(int fd[], char **cmd2, char *outfile, char **envp)
{
	pid_t		pid2;

	pid2 = fork();
	if (pid2 == -1)
	{
		perror("Error in fork (second child)");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		setup_child2(fd, outfile);
		execute_command(cmd2, envp);
		perror("Error in execve (second child)");
		exit(EXIT_FAILURE);
	}
	return (pid2);
}
