/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:47:31 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/03 17:09:35 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	while (n--)
	{
		*ss = 0;
		ss++;
	}
}
/*Fills a block of memory with zeroes (use memset instead).*/
