/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:53:28 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/02 18:49:09 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;

	i = (unsigned char) c;
	while (*s != '\0')
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == 0)
		return ((char *)s);
	return (0);
}
/*Finds the last occurrence of a character in a string.*/
