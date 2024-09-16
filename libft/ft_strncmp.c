/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:08:03 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/02 17:46:35 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function compares the first `n` characters of the strings `s1` and `s2`.
// It returns an integer less than, equal to, or greater than zero if `s1` is found to be less than, equal to, or greater than `s2`, respectively.
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
        i++;
    if (i == n) // If the first `n` characters are equal
        return (0); // Return 0 to indicate equality
    return ((unsigned char) s1[i] - (unsigned char)s2[i]); // Return the difference between characters
}

/*Compares a specified number of characters in two strings.*/
