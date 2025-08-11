/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:15:48 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/25 13:24:56 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest [i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
/*
int main ()
{
    char    a[10] = "";
    char    b[] = "Hello, World!";
    unsigned int    s = 10;
   printf("%d", ft_strlcpy(a, b, s));
    return(0);
}*/
