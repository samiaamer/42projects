/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:58:28 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/04 15:19:56 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


// This function compares the first `n` bytes of two memory blocks `s1` and `s2`.
// It returns an integer less than, equal to, or greater than zero, depending on whether `s1` is less than, equal to, or greater than `s2`.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	i = 0;
	ss1 = (const unsigned char *) s1;
	ss2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i])// Compare the current bytes
			return (ss1[i] - ss2[i]);// Return the difference if bytes are different
		i++;
	}
	return (0);
}
/*
int main()
{
	const char s1[] = "samia";
	const char s2[] = "aqq";
	printf("%d\n", ft_memcmp(s1,s2,3));
	return 0;
}*/
/*Compares two blocks of memory.*/
