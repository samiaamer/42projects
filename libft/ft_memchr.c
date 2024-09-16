/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:09:51 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/04 12:29:01 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// This function locates the first occurrence of a specified character `c` in the memory block `s`.
// It searches within the first `n` bytes of the memory block.
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	unsigned char	cc; 

	ss = (const unsigned char *)s;// Cast the memory block to an unsigned char pointer
	cc = (unsigned char)c;// Cast the search character to unsigned char
	while (n--)// Loop through the memory block
	{
		if (*ss == cc)// Check if the current byte matches the search character
			return ((void *)ss);// Return a pointer to the matching byte
		ss++;
	}
	return(0);
}
/*Finds the first occurrence of a value in a block of memory.*/
