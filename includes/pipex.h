/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:31:34 by marvin            #+#    #+#             */
/*   Updated: 2025/05/31 10:31:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

void	pipex(char *files[], char *cmd1[], char *cmd2[], char **envp);
pid_t	execute_child1(int fd[], char **cmd1, char *infile, char **envp);
pid_t	execute_child2(int fd[], char **cmd2, char *outfile, char **envp);
void	execute_command(char **args, char **envp);
char	*find_path(char *cmd, char **envp);
char	**get_paths_from_env(char **envp);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, unsigned int n);
void	ft_putstr_fd(char *s, int fd);

#endif