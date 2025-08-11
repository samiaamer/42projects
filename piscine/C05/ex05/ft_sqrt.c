/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:04:36 by sabutale          #+#    #+#             */
/*   Updated: 2024/07/01 12:09:37 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	res;

	res = 0;
	while (res * res <= nb)
	{
		if (res * res == nb)
			return (res);
		res++;
	}
	return (0);
}
/*
int main()
{
    printf("%d", ft_sqrt(-4));
    return(0);
}*/
