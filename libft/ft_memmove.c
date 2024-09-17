/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:58:55 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/05 17:21:54 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function copies `n` bytes from the source memory block `src` to the destination memory block `dest`.
// It handles overlapping memory regions correctly.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
  s = (const unsigned char *) src;
	if (s == NULL && d == NULL)// Check for null pointers
		return (NULL);
	if (s > d)// If source is after destination in memory
	{
		return (ft_memcpy(dest, src, n));// Use memcpy if no overlap
	}
	else if (d > s) // If destination is after source in memory
	{
		i = n;// Set index to the number of bytes
		while (i--)// Move from the end to the beginning
			d[i] = s[i];// Copy each byte from source to destination
	}
	return (dest);
}
/*int main()
{
	const char src[] ="samia";
	printf("%s", ft_memmove(src +2 , src, 3));
	return (0);
}*/
