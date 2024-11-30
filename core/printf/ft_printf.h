/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:05:11 by sabutale          #+#    #+#             */
/*   Updated: 2024/10/02 18:05:44 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_print_string(const char *str);
int	ft_print_char(char c);
int	ft_print_integer(int num);
int	ft_print_unsigned(unsigned int num);
int	ft_print_hex(unsigned long num, char specifier);
int	ft_print_pointer(void *ptr);
int	ft_printf(const char *format, ...);

#endif
