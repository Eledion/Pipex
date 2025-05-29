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

#include "pipex.h"

void execute_command(char **args)
{
	char *path;

	path = find_path(args[0]);
	if (!path)
	{
		perror("Error: command doesnt found");
		exit(EXIT_FAILURE);
	}
	execve(path, args, NULL);
	perror("Error on execve");
	free(path);
	exit(EXIT_FAILURE);
}
