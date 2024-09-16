/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:46:24 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/02 11:52:21 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')// Skip any whitespace characters (space, tab, etc.) at the beginning
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')// Check for a sign indicator ('-' or '+') and adjust the sign variable
	{
		if (nptr[i] == '-')
			sign = -1;// Set sign to -1 for negative numbers
		i++;// Move past the sign character
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')// Convert the string representation of the number to an integer
	{
		res = res * 10 + nptr[i] - '0';// Update result by shifting previous digits and adding the new digit
		i++;
	}
	return (sign * res);
}
/*
int main()
{
	 const char *test1 = "123";
	  printf("ft_atoi(\"%s\") = %d\n", test1, ft_atoi(test1));
		 return 0;
}*/
/* Converts a string to an integer.*/
