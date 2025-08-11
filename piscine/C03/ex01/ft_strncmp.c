/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:09:28 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/28 14:50:49 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (i == n)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char	a[] = "A";
	char	b[] = "amia";
	int	i = 1;
	printf("%d",ft_strncmp(a,b,i));
	return (0);
}*/
