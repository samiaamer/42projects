/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:32:31 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/03 12:03:37 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function locates the last occurrence of the character `c` in the string `s`.
// It returns a pointer to the last occurrence of `c`, or NULL if `c` is not found.
char *ft_strrchr(const char *s, int c)
{
    unsigned char j;
    int len;

    len = ft_strlen(s); // Get the length of the string
    j = (unsigned char)c; // Cast `c` to unsigned char
    if (j == 0) // Special case for the null terminator
        return ((char *)s + len); // Return a pointer to the null terminator
    while (len >= 0)
    {
        if (s[len] == j) // Check if the current character matches `c`
            return ((char *)s + len); // Return a pointer to the last occurrence
        len--;
    }
    return (0); // Return NULL if `c` is not found
}

/*Finds the last occurrence of a character in a string.*/
