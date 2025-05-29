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

char **get_paths_from_env()
{
    char *path_env = getenv("PATH");
    if (!path_env)
    {
        perror("Error: Path doesn't exist");
        return (NULL);
    }
    return (ft_split(path_env, ':'));
}

char *search_command_in_paths(char *cmd, char **paths)
{
    char *path;
    char *temp;
    int i = 0;

    while (paths[i])
    {
        temp = ft_strjoin(paths[i], "/");
        path = ft_strjoin(temp, cmd);
        free(temp);

        if (access(path, X_OK) == 0)
        {
            while (paths[i])
                free(paths[i++]);
            free(paths);
            return path;
        }
        free(path);
        i++;
    }
    while (paths[i])
        free(paths[i++]);
    free(paths);
    return (NULL);
}

char *find_path(char *cmd)
{
    char **paths = get_paths_from_env();
    if (!paths)
        return NULL;
    return (search_command_in_paths(cmd, paths));
}