/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:32:31 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/03 12:03:37 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
		unsigned char	j;
	int	len;

	len = ft_strlen(s) - 1;
	j = (unsigned char) c;
	while (len >= 0)
	{
		if (s[len] == j)
			return ((char *)s + len);
		len--;
	}
	if (j == 0)
		return ((char *)s + len);
	return (0);
}
