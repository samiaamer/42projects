/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:37:00 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/23 12:07:55 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (! (65 <= str[i] && str [i] <= 90))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
int     main(void)
{
char    a[]= "GDsSG" ;
int     b = ft_str_is_uppercase(a);

printf("%i", b);
return (0);
}*/
