/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:55:29 by marvin            #+#    #+#             */
/*   Updated: 2025/05/31 09:55:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	char	*cmd1[2];
	char	*cmd2[2];

	if (argc != 5)
	{
		ft_putstr_fd("Error: Usage -> ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (EXIT_FAILURE);
	}
	if (!argv[2] || !argv[3])
	{
		ft_putstr_fd("Error: Invalid command arguments\n", 2);
		return (EXIT_FAILURE);
	}
	cmd1[0] = argv[2];
	cmd1[1] = NULL;
	cmd2[0] = argv[3];
	cmd2[1] = NULL;
	pipex(argv[1], cmd1, cmd2, argv[4]);
	return (EXIT_SUCCESS);
}
