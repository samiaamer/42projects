/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:39:41 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/28 14:51:38 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*pointer;

	pointer = dest;
	while (*pointer != '\0')
		pointer++;
	while (*src != '\0')
	{
		*pointer = *src;
		src++;
		pointer++;
	}
	*pointer = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	a[] = "samia";
	char	b[] = "amer";
	printf("%s",ft_strcat(a,b));
	return (0);
}*/
