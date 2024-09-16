/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:01 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/12 14:03:03 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	count_digit(int n)
{// This function calculates the number of digits required to represent an integer `n` as a string.
	int	len;

	len = 0;
	if (n <= 0)// Check if the number is negative or zero
		len++;// Account for the minus sign 
	while (n != 0) // Loop until all digits are counted
	{
		n /= 10;// Remove the last digit from the number
		len++;// Increase the digit count
	}
	return (len);// Return the total digit count
}

// This function converts an integer `n` to a string and stores it in `res`.
// It handles the placement of digits and sign based on the `sign` value.
static void	makeString(char *res, int n, int len, int sign)
{
	res[len] = '\0';// Null-terminate the string
	if (n == 0)// Special case for zero
		res[0] = '0';
	while (len > 0) // Fill the string with digits
	{
		res[--len] = (n % 10) + '0';// Extract last digit and convert to character
		n /= 10;// Remove last digit from the number
	}
	if (sign == -1)// If the number was negative
	{
		res[0] = '-';// Add the minus sign at the beginning
	}
}

// This function converts an integer `n` to a dynamically allocated string.
char	*ft_itoa(int n)
{
	int	sign;
	int	len;
	char	*res;

	sign = 1;
	len = count_digit(n);// Calculate the length of the string needed
	if (n == -2147483648)// Special case for the smallest integer value
		return ft_strdup("-2147483648");
	if (n < 0)// If the number is negative
	{
		n = -n;// Make `n` positive
		sign = -1;// Indicate negative sign
	}
	res = malloc(len + 1);// Allocate memory for the resulting string
	if (!res)
		return (NULL);// Return NULL if allocation fails
	makeString(res, n, len, sign);// Convert the number to a string
	return (res);// Return the resulting string
}
