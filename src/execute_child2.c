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

pid_t execute_child2(int fd[], char **cmd2, char *outfile)
{
    extern char **environ;
    pid_t pid2;

    pid2 = fork();
    if (pid2 == -1)
    {
        perror("Error en fork (segundo hijo)");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0)
    {
        close(fd[1]);
        if (dup2(fd[0], STDIN_FILENO) == -1)
        {
            perror("Error duplicando fd[0] a STDIN");
            exit(EXIT_FAILURE);
        }
        close(fd[0]);
        int fd_out = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fd_out < 0)
        {
            perror("Error al abrir archivo de salida");
            exit(EXIT_FAILURE);
        }
        if (dup2(fd_out, STDOUT_FILENO) == -1)
        {
            perror("Error duplicando fd_out a STDOUT");
            exit(EXIT_FAILURE);
        }
        close(fd_out);
        execute_command(cmd2, environ);
        perror("Error en execve (segundo hijo)");
        exit(EXIT_FAILURE);
    }
    return pid2;
}