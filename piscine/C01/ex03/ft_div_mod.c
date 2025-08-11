/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:11:30 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/10 12:28:51 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main (void)
{
	int	a = 25;
	int	b = 5;
	int	div;
	int	mod;
	ft_div_mod(a, b, &div, &mod);
	printf(" div: %d", div);
	printf("\n");
	printf(" mod: %d", mod);
	return (0);
}*/
