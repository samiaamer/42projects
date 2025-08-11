/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:07:19 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/23 15:56:31 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (str + i);
			}
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (0);
}
/*
int main() {
    char s[] = "samia";
    char a[] = "m";

        printf("%s\n", ft_strstr(s,a)); 
    return 0;
}*/
