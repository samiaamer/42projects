/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:36:26 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/10 11:55:03 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
	int	a = 1;
	int	b = 3;
	int	*ptra = &a;
	int	*ptrb = &b;
	
	ft_swap(ptra, ptrb);
	printf(" a: %d", a);
	printf("\n");
	printf(" b: %d", b);
	return (0);
}*/
