/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:01 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/17 12:32:16 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	make_string(char *res, int n, int len, int sign)
{
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (len > 0)
	{
		res[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
	{
		res[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*res;

	sign = 1;
	len = count_digit(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	make_string(res, n, len, sign);
	return (res);
}
