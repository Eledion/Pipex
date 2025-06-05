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

static char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (ft_strncmp(env[i], name, j) == 0 && env[i][j] == '=')
			return (env[i] + j + 1);
		i++;
	}
	return (NULL);
}

static char	**get_paths_from_env(char **envp)
{
	char	*path_env;

	if (!envp)
	{
		ft_putstr_fd("Error: envp is NULL\n", 2);
		return (NULL);
	}
	path_env = my_getenv("PATH", envp);
	if (!path_env)
	{
		ft_putstr_fd("Error: PATH variable missing\n", 2);
		return (NULL);
	}
	return (ft_split(path_env, ':'));
}

static char	*find_executable_path(char *directory, char *cmd)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(directory, "/");
	path = ft_strjoin(temp, cmd);
	free(temp);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}

static char	*search_command_in_paths(char *cmd, char **paths)
{
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = find_executable_path(paths[i], cmd);
		if (path)
		{
			while (paths[i])
				free(paths[i++]);
			free(paths);
			return (path);
		}
		i++;
	}
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;

	paths = get_paths_from_env(envp);
	if (!cmd || !cmd[0])
		return (NULL);
	if (!paths)
		return (NULL);
	return (search_command_in_paths(cmd, paths));
}
