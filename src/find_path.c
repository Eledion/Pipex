/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:00:44 by marvin            #+#    #+#             */
/*   Updated: 2025/05/29 12:00:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char **get_paths_from_env()
{
    char *path_env = getenv("PATH");
    if (!path_env)
    {
        ft_putstr_fd("Error: PATH variable missing\n", 2);
        return NULL;
    }
    return ft_split(path_env, ':');
}

char *find_executable_path(char *directory, char *cmd)
{
    char *temp = ft_strjoin(directory, "/");
    char *path = ft_strjoin(temp, cmd);
    free(temp);
    if (access(path, X_OK) == 0)
        return path;
    free(path);
    return NULL;
}

char *search_command_in_paths(char *cmd, char **paths)
{
    char *path;
    int i = 0;

    while (paths[i])
    {
        path = find_executable_path(paths[i], cmd);
        if (path)
        {
            while (paths[i])
                free(paths[i++]);
            free(paths);
            return path;
        }
        i++;
    }
    while (paths[i])
        free(paths[i++]);
    free(paths);
    return NULL;
}

char *find_path(char *cmd)
{
    if (!cmd || !cmd[0])
        return NULL;
    char **paths = get_paths_from_env();
    if (!paths)
        return NULL;
    return search_command_in_paths(cmd, paths);
}