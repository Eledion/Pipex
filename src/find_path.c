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

// 🔹 Obtiene las rutas del entorno
char **get_paths_from_env()
{
    char *path_env = getenv("PATH");
    if (!path_env)
    {
        ft_printf("Error: PATH variable missing\n", 2);
        return NULL;
    }
    return ft_split(path_env, ':'); // Separa por ':'
}

// 🔹 Busca el ejecutable en los directorios de $PATH
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
            int j = 0;
            while (paths[j])
            {
                free(paths[j]);
                j++;
            }
            free(paths);
            return path;
        }
        free(path);
        i++;
    }

    // 🔹 Liberación segura si no se encuentra el ejecutable
    i = 0;
    while (paths[i])
    {
        free(paths[i]);
        i++;
    }
    free(paths);
    
    return NULL;
}

// 🔹 Encuentra la ruta del ejecutable, no los argumentos
char *find_path(char *cmd)
{
    if (!cmd || !cmd[0]) // Validación de entrada
        return NULL;
    
    char **paths = get_paths_from_env();
    if (!paths)
        return NULL;

    return search_command_in_paths(cmd, paths);
}