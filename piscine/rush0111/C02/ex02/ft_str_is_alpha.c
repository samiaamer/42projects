/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:08:24 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/23 12:04:43 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (! ('a' <= str[i] && str[i] <= 'z'))
		{
			if (! ('A' <= str[i] && str[i] <= 'Z'))
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char	a[] = "s7amia";
	int	b = ft_str_is_alpha(a);
	printf("%i", b);
	return (0);
}*/
