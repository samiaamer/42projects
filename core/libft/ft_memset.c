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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	while (n--)
	{
		*ss = (unsigned char)c;
		ss++;
	}
	return (s);
}
/*Sets a block of memory to a specified value*/
