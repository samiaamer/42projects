/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:43:20 by sabutale          #+#    #+#             */
/*   Updated: 2024/10/01 16:12:38 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include <limits.h>

static int	handle_format(char format, va_list args)
{
	if (format == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 'd' || format == 'i')
		return (ft_print_integer(va_arg(args, int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == '%')
		return (write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += handle_format(format[++i], args);
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main(void)
{
   ft_printf("String: %s\n", "Hello, World!");
    ft_printf("Character: %c\n", 'A');
    ft_printf("Integer: %d\n", 42);
    ft_printf("Negative Integer: %d\n", -42);
    ft_printf("Unsigned Integer: %u\n", 42);
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Hexadecimal (lowercase): %x\n", 255);
    ft_printf("Hexadecimal (uppercase): %X\n", 255);
    ft_printf("Percent symbol: %%\n");
    printf("%d", ft_printf("%s", NULL));
	ft_printf("String: %s\n", "Hello, World!");
	printf(" NULL %s NULL \n", NULL);
   ft_printf(" %p\n %p \n", 0, 0);
	ft_printf("String: %s\n", "Hello, World!");
    ft_printf(" %x \n", 0);
	ft_printf("String: %s\n", "Hello, World!");
    ft_printf(" %x \n", LONG_MIN);
	ft_printf("String: %s\n", "Hello, World!");
	ft_printf(" %x \n", LONG_MIN);
    return 0;
}*/
