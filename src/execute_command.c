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

char **prepare_command(char **args)
{
    if (!args || !args[0])
    {
        ft_putstr_fd("Error: No command provided\n", 2);
        exit(EXIT_FAILURE);
    }
    char **cmd_args = ft_split(args[0], ' ');
    if (!cmd_args)
    {
        ft_putstr_fd("Error: Failed to split command\n", 2);
        exit(EXIT_FAILURE);
    }
    remove_quotes(cmd_args);
    return cmd_args;
}

char *get_command_path(char **cmd_args)
{
    char *cmd_path = find_path(cmd_args[0]);

    if (!cmd_path)
    {
        ft_putstr_fd("Error: Command not found \n", 2);
        int i = 0;
        while (cmd_args[i] != NULL)
        {
            free(cmd_args[i]);
            i++;
        }
        free(cmd_args);
        exit(EXIT_FAILURE);
    }
    return cmd_path;
}

void execute_command(char **args, char **envp)
{
    char **cmd_args = prepare_command(args);
    char *cmd_path = get_command_path(cmd_args);
    if (execve(cmd_path, cmd_args, envp) == -1)
    {
        perror("Error in execve");
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