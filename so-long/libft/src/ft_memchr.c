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

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	unsigned char		cc;

	ss = (const unsigned char *)s;
	cc = (unsigned char)c;
	while (n--)
	{
		if (*ss == cc)
			return ((void *)ss);
		ss++;
	}
	return (0);
}
