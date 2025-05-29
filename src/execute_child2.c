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

void    execute_child2(int fd[], char *cmd2[])
{
    pid_t   pid2;
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("Error on fork (second child)");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execute_command(cmd2);
        perror("Error on execve (second child)");
        exit(EXIT_FAILURE);
    }
}