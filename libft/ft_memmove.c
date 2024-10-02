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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (s == NULL && d == NULL)
		return (NULL);
	if (s > d)
	{
		return (ft_memcpy(dest, src, n));
	}
	else if (d > s)
	{
		i = n;
		while (i--)
			d[i] = s[i];
	}
	return (dest);
}
/*int main()
{
	const char src[] ="samia";
	printf("%s", ft_memmove(src +2 , src, 3));
	return (0);
}*/
