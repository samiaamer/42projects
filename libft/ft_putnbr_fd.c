/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:34:11 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/08 16:42:55 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function writes an integer `nb` to the file descriptor `fd` as a string.
void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)// Special case for the smallest integer
	{
		write (fd, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);// Write the minus sign
		nb = -nb;// Make the number positive
		ft_putnbr_fd(nb, fd);// Recursively handle the positive part
	}
	else if (nb > 9)// If the number has more than one digit
	{
		ft_putnbr_fd(nb / 10, fd);// Recursively handle the first part
		ft_putnbr_fd(nb % 10, fd);// Handle the last digit
	}
	else// If the number is a single digit
		ft_putchar_fd(nb + 48, fd);// Convert the digit to a character and write it
}
