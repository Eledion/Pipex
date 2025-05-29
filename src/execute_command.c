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

static void remove_quotes(char **tokens)
{
    int i = 0;
    while (tokens[i] != NULL)
    {
        size_t len = strlen(tokens[i]);
        if (len >= 2)
        {
            if ((tokens[i][0] == '\'' && tokens[i][len - 1] == '\'') ||
                (tokens[i][0] == '"'  && tokens[i][len - 1] == '"'))
            {
                ft_memmove(tokens[i], tokens[i] + 1, len - 2);
                tokens[i][len - 2] = '\0';
            }
        }
        i++;
    }
}

void execute_command(char **args, char **envp)
{
    if (!args || !args[0])
    {
        ft_printf("Error: No command provided\n", 2);
        exit(EXIT_FAILURE);
    }

    // Separa el comando en tokens usando ft_split (no controlamos su implementación interna)
    char **cmd_args = ft_split(args[0], ' ');
    if (!cmd_args)
    {
        ft_printf("Error: Failed to split command\n", 2);
        exit(EXIT_FAILURE);
    }
    remove_quotes(cmd_args);
    char *cmd_path = find_path(cmd_args[0]);
    if (!cmd_path)
    {
        ft_printf("Error: Command not found -> %s\n", cmd_args[0], 2);
        int i = 0;
        while (cmd_args[i] != NULL)
        {
            free(cmd_args[i]);
            i++;
        }
        free(cmd_args);
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (cmd_args[i] != NULL)
    {
        ft_printf("cmd_args[%d]: %s\n", i, cmd_args[i]);
        i++;
    }

    // Ejecutar el comando
    if (execve(cmd_path, cmd_args, envp) == -1)
    {
        perror("Error en execve");
        free(cmd_path);
        int j = 0;
        while (cmd_args[j] != NULL)
        {
            free(cmd_args[j]);
            j++;
        }
        free(cmd_args);
        exit(EXIT_FAILURE);
    }
}
