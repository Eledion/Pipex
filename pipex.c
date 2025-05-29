/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:25:50 by marvin            #+#    #+#             */
/*   Updated: 2025/05/28 12:25:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "ft_printf.h"

char *findpath(char *cmd)
{
	char	*path_env;
	char	*path;
	char	**token;
	int		i;
	char	*temp;
	path_env = getenv("PATH");
	if (!path_env)
	{
		perror("Error: Path doesnt exist");
		return (NULL);
	}
	token = ft_split(path_env, ':');
	if (!token)
		return (NULL);
	i = 0;
	while (token[i])
	{
		temp = ft_strjoin(token[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
		{
			free(token);
			return (path);
		}
		free(path);
		i++;
	}
	while (token[i])
	{
		free(token[i]);
		i--;
	}
	free(token);
	return (NULL);
}

void execute_command(char *cmd, char **args)
{
	char *path;

	path = findpath(cmd);
	if (!path)
	{
		ft_printf("Error: comando no encontrado");
		exit(EXIT_FAILURE);
	}
	execve(path, args, NULL);
	perror("Error en execve");
	free(path);
	exit(EXIT_FAILURE);
}

int	main()
{
	char *args[] = {"ls", "-l", NULL};
	execute_command("ls", args);
	return (0);
}