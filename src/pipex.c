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

void pipex(char *infile, char *cmd1[], char *cmd2[], char *outfile)
{
    int fd[2];
    
    (void) infile;
    (void) outfile;
    if (pipe(fd) == -1)
    {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }
    execute_child1(fd, cmd1);
    execute_child2(fd, cmd2);
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
}
