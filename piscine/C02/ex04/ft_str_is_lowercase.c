/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:39:18 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/23 18:16:16 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (! (97 <= str[i] && str [i] <= 122))
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
char    a[]= "sSdg" ;
int     b = ft_str_is_lowercase(a);

printf("%i", b);
return (0);
}*/
