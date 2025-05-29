/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:23:33 by danoguer          #+#    #+#             */
/*   Updated: 2025/05/29 12:57:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	contar(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_split(char **split, int hasta)
{
	int	i;

	i = 0;
	while (i < hasta)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	fill_split(char **result, const char *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		result[k] = ft_substr(s, start, i - start);
		if (!result[k])
		{
			free_split(result, k);
			return (0);
		}
		k++;
	}
	result[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (contar(s, c) + 1));
	if (!result)
		return (NULL);
	if (!fill_split(result, s, c))
		return (NULL);
	return (result);
}
