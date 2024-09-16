/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:33:46 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/08 11:50:16 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function extracts a substring from `s`, starting at `start` with a length of `len`.
// It returns the substring or an empty string if `start` is out of bounds.
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t slen;

    slen = ft_strlen(s); // Get the length of the source string

    if (!s) // Check if the source string is NULL
        return (NULL);

    if (start >= slen) // If start index is out of bounds, return an empty string
        return (ft_strdup(""));

    if (len > slen - start) // Adjust length if it exceeds the remaining string length
        len = slen - start;

    substr = malloc(sizeof(char) * (len + 1)); // Allocate memory for the substring
    if (!substr)
        return (NULL);

    // Copy the substring from `s` to `substr`
    ft_memcpy(substr, s + start, len);
    substr[len] = '\0'; // Null-terminate the substring

    return (substr); // Return the substring
}

