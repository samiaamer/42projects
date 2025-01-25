/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:32:31 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/17 12:37:12 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	j;
	int				len;

	len = ft_strlen(s);
	j = (unsigned char)c;
	if (j == 0)
		return ((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == j)
			return ((char *)s + len);
		len--;
	}
	return (0);
}
