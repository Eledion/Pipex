/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:36:30 by danoguer          #+#    #+#             */
/*   Updated: 2025/04/08 15:49:08 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*chardest;
	unsigned char	*charsrc;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	chardest = (unsigned char *)dest;
	charsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		chardest[i] = charsrc[i];
		i++;
	}
	return (dest);
}
