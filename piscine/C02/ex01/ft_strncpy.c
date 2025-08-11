/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:57:28 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/24 13:39:57 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	a[] = "World1";
	char	b[] = "Hello";
	int	c = 3;

	ft_strncpy(a, b, c);
	printf("%s", a);
	printf("%s", ft_strncpy("World1", "Hello", 3));
	printf("%s", ft_strncpy("World1", "Hello", 5));
	printf("%s", ft_strncpy("World1", "Hello", 7));
	//return (0);
//}*/
