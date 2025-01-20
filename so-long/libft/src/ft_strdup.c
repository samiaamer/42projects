/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:52:31 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/17 11:52:33 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	leng;
	char	*new;

	leng = ft_strlen(s);
	new = malloc(leng + 1);
	if (!new)
		return (0);
	ft_memcpy(new, s, leng + 1);
	return (new);
}
