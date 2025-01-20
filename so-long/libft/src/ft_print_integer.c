/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:08:13 by sabutale          #+#    #+#             */
/*   Updated: 2024/10/01 16:08:40 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_print_integer(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		count += write (1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		count += ft_print_integer(num / 10);
	count += ft_print_char(num % 10 + '0');
	return (count);
}
