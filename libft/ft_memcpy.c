/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:33:07 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/04 12:47:09 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// This function copies `n` bytes from the source memory block `src` to the destination memory block `dest`.
// It does not handle overlapping memory regions.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if( !dest && !src )
		return (0);
	while (i < n)
	{
		d[i] = s[i];// Copy each byte from source to destination
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char	src[] = "samia amer";
	char	dest[20];
	ft_memcpy(dest, src, 11);
	printf("destenation %s", dest);
	return(0);
}*/
/*Copies a block of memory from one location to another.*/
