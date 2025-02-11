/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:08:57 by sabutale          #+#    #+#             */
/*   Updated: 2024/10/01 16:09:20 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_print_unsigned(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_print_unsigned(num / 10);
	count += ft_print_char(num % 10 + '0');
	return (count);
}
