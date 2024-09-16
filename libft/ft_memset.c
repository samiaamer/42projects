/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:24:04 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/03 11:55:48 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function sets the first `n` bytes of the memory block `s` to the value `c`.
// It initializes a block of memory with a specified value.
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	while (n--)// Loop through the memory block
	{
		*ss = (unsigned char) c;// Set the current byte to the specified value
		ss++;
	}
	return (s);// Return the pointer to the memory block
}
/*Sets a block of memory to a specified value*/
