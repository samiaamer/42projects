/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:47:31 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/03 17:09:35 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{// This function sets the first `n` bytes of the memory area pointed to by `s` to zero.
	unsigned char	*ss;

	ss = (unsigned char *)s;// Cast the pointer to `unsigned char*` for byte-by-byte manipulation
	while (n--)// Loop through each byte
	{
		*ss = 0;// Set the current byte to 0
		ss++; // Move to the next byte
	}
	//ft_memset(s,0,n);
}
/*Fills a block of memory with zeroes (use memset instead).*/
