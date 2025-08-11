/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:26:32 by sabutale          #+#    #+#             */
/*   Updated: 2024/07/01 14:18:12 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	if (nb > 1)
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
	return (0);
}
/*
int main ()
{
    int n = 5;
    printf("%d", ft_recursive_factorial(n));
    return (0);
}*/
