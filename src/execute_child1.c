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

void setup_child1(int fd[], char *infile)
{
    int fd_in = open(infile, O_RDONLY);
    if (fd_in < 0)
    {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    dup2(fd_in, STDIN_FILENO);
    close(fd_in);
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
}

pid_t execute_child1(int fd[], char **cmd1, char *infile)
{
    extern char **environ;
    pid_t pid1;

    pid1 = fork();
    if (pid1 == -1)
    {
        perror("Error in fork (first child)");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0)
    {
        setup_child1(fd, infile);
        execute_command(cmd1, environ);
        perror("Error in execve (first child)");
        exit(EXIT_FAILURE);
    }
    return pid1;
}