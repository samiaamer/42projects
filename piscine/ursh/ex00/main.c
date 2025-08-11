/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:13:41 by sabutale          #+#    #+#             */
/*   Updated: 2024/06/29 19:17:20 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	NumberToText(unsigned long Number)
{
	int i;
	char *arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	char *tensArr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

	i = 0;
	if (Number >= 1 && Number <= 19)
	{
		while(arr[Number][i] != '\0')
		{
			write (1, &arr[Number][i], 1);
			i++;
		}
		write (1, " ", 1);
	}
	i = 0;
	if (Number >= 20 && Number <= 99)
	{
		while (tensArr[Number / 10][i] != '\0')
		{
			write (1, &tensArr[Number / 10][i] , 1);
			i++;
		}
		write (1, " " , 1);
		NumberToText(Number % 10);
	}
	i = 0;
	if (Number >= 100 && Number <= 199)
	{
		write (1, " One Hundred ", 13);
		NumberToText(Number % 100);
	}
	if (Number >= 200 && Number <= 999)
	{
		NumberToText (Number / 100);
		write (1, " Hundreds ", 10);
		NumberToText (Number % 100);
	}
	if (Number >= 1000 && Number <= 1999)
	{
		write (1, " One Thousand ", 14);
		NumberToText (Number % 1000);
	}
	if (Number >= 2000 && Number <= 999999)
	{
		NumberToText(Number / 1000);
		write (1, " Thousands ", 11);
		NumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 1999999)
	{
		write (1, " One Million ", 12);
		NumberToText(Number % 1000000);
	}
	if (Number >= 2000000 && Number <= 999999999)
	{
		NumberToText(Number / 1000000);
		write (1, " Millions ", 10);
		NumberToText(Number % 1000000);
	}
	if (Number >= 1000000000 && Number <= 1999999999)
	{
		write (1, " One Billion ", 13);
		NumberToText(Number % 1000000000);
	}
	if (Number >= 2000000000 && Number <= 999999999999)
	{
		NumberToText(Number / 1000000000);
		write (1, " Billions ", 10);
		NumberToText(Number % 1000000000);
	}
}

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

int	main(int argc, char **argv)
{
	NumberToText(ft_atoi(argv[1]));
	return (0);
}
