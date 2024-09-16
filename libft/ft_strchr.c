/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:53:28 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/02 18:49:09 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function locates the first occurrence of the character `c` in the string `s`.
char *ft_strchr(const char *s, int c)
{
    unsigned char i;

    i = (unsigned char)c; // Cast `c` to unsigned char
    while (*s != '\0') // Loop through the string
    {
        if (*s == i) // Check if the current character matches `c`
            return ((char *)s); // Return a pointer to the first occurrence
        s++; // Move to the next character
    }
    if (i == 0) // Special case for the null terminator
        return ((char *)s); // Return a pointer to the null terminator
    return (0); // Return NULL if the character is not found
}

/*Finds the first occurrence of a character in a string.*/
