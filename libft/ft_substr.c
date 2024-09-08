/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:33:46 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/08 11:50:16 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_length;

	i = 0;
	s_length = ft_strlen(s);
	substr = malloc(s_length + 1);
	if (!s)
		return (0);
	if (start > s_length)
		return (0);
	if (len > s_strlength - start)
		return (0);
	while (i < len && s[start + i] != '\0' )
	{
		substr[i] = s[start + i];
		i++;
	}
	subst[i] = '\0';
	return (substr);
}
