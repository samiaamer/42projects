/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:14:45 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/07 16:33:40 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	comm(char a, char b, char c)
{
	if (!(a == '7' && b == '8' && c == '9'))
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	y;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			y = j + 1;
			while (y <= '9')
			{
				write(1, &i, 1);
				write(1, &j, 1);
				write(1, &y, 1);
				comm(i, j, y);
				y++;
			}
			j++;
		}
		i++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}*/
