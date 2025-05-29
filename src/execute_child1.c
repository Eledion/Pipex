/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executechild1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:54:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/29 10:54:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    execute_child1(int fd[], char *cmd1[])
{
    pid_t   pid1;
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("Error on fork (first child)");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execute_command(cmd1);
        perror("Error on execve (first child)");
        exit(EXIT_FAILURE);
    }
}
