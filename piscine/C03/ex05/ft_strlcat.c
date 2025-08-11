/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:17:50 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/23 15:58:12 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	while (dest[i] != '\0' && i < size - 1)
		i++;
	while (i < size - 1 && src[i - dest_len] != '\0')
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
/*
int	main()
{
	char dest[20] = "Hello, ";
	char src[] = "world!";
	unsigned int size = 20;
	unsigned int length = ft_strlcat(dest, src, size);
	printf("%d\n", length);
	return (0);
}*/
