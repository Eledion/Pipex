/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:50:14 by danoguer          #+#    #+#             */
/*   Updated: 2025/04/09 19:16:22 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned char	*chardest;
	unsigned char	*charsrc;

	if (!dest && !src)
		return (NULL);
	chardest = (unsigned char *)dest;
	charsrc = (unsigned char *)src;
	if (chardest < charsrc)
	{
		while (n--)
			*chardest++ = *charsrc++;
	}
	else
	{
		while (n > 0)
		{
			chardest[n - 1] = charsrc[n - 1];
			n--;
		}
	}
	return (dest);
}
