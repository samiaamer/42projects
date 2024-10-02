/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:09:30 by sabutale          #+#    #+#             */
/*   Updated: 2024/10/01 16:09:52 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long num, char specifier)
{
	int		count;
	char	*hex_dig;

	count = 0;
	if (num == 0)
		count += write(1, "0", 1);
	else
	{
		if (specifier == 'x')
			hex_dig = "0123456789abcdef";
		else
			hex_dig = "0123456789ABCDEF";
		if (num >= 16)
			count += ft_print_hex(num / 16, specifier);
		count += ft_print_char(hex_dig[num % 16]);
	}
	return (count);
}
