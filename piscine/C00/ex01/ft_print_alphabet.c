/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:45:39 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/07 16:25:10 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_print_alphabet(void)
{
	char	x;

	x = 'a';
	while (x <= 'z')
	{
		write(1, &x, 1);
		x++;
	}
	return (0);
}
/*
int	main(void)
{
	ft_print_alphabet();
	return (0);
}*/
