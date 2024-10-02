/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:10:12 by sabutale          #+#    #+#             */
/*   Updated: 2024/10/01 16:10:42 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_print_pointer(void *ptr)
{
        int     count;

        count = 0;
        if (!ptr)
                return (write(1, "(nil)", 5));
        count += write(1, "0x", 2);
        count += ft_print_hex((unsigned long)ptr, 'x');
        return (count);
}
