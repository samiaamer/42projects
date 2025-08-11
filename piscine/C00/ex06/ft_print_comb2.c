/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:11:56 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/21 14:23:55 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char a, char b, char c, char d)
{
	write (1, &a, 1);
	write (1, &b, 1);
	write (1, " ", 1);
	write (1, &c, 1);
	write (1, &d, 1);
	if (!(a == '9' && b == '8' && c == '9' && d == '9'))
	{
		write (1, ", ", 2);
	}
}

void	ft_while(char a, char b, char c, char d)
{
	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '8')
		{
			c = '0';
			while (c <= '9')
			{
				d = '1';
				while (d <= '9')
				{
					print (a, b, c, d);
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	d;
	char	b;
	char	c;

	a = '0';
	b = '0';
	c = '0';
	d = '1';
	ft_while(a, b, c, d);
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
