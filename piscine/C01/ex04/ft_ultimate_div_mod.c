/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:30:21 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/10 12:37:37 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	x;
	int	y;

	x = *a / *b;
	y = *a % *b;
	*a = x;
	*b = y;
}
/*
int main(void)
{
	int 	a = 4;
	int	b = 2;

	ft_ultimate_div_mod(&a, &b);
	printf(" a: %d", a);
	printf("\n");
	printf(" b: %d", b);
	return(0);
}*/
