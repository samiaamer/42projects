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
static void	makeString(char *res, int n, int len, int sign)
{
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[--len + (sign == -1)] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
	{
		res[0] = '-';
	}
}
char	*ft_itoa(int n)
{
	int	sign;
	int	len;
	char	*res;

	sign = 1;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	} 
	len = count_digit(n);
	res = malloc(len + 1 + (sign == -1));
	if (!res)
		return (NULL);
	makeString(res, n, len, sign);
	return (res);
}
